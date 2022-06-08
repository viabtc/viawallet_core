#include <TrezorCrypto/kadena/kadena_encrypted_sign.h>

#define NB_ITERATIONS 15000


#define ROTATE(v,c) (ROTL32(v,c))
#define XOR(v,w) ((v) ^ (w))
#define PLUS(v,w) (U32V((v) + (w)))
#define PLUSONE(v) (PLUS((v),1))

typedef struct {
	uint8_t pkey[PUBLIC_KEY_SIZE];
	uint8_t cc[CHAIN_CODE_SIZE];
} public_key;

typedef union {
    uint64_t q[8];
    uint32_t d[16];
    uint8_t  b[64];
} block;

typedef block cryptonite_chacha_state;

typedef struct {
    cryptonite_chacha_state st;
    uint8_t prev[64];
    uint8_t prev_ofs;
    uint8_t prev_len;
    uint8_t nb_rounds;
} cryptonite_chacha_context;



void clear(void *buf)
{
        memzero(buf, sizeof(buf));
}

int index_is_hardened(uint32_t index)
{
    return (index & (1 << 31));
}

void add_256bits_v1(uint8_t *dst, uint8_t *src1, uint8_t *src2)
{
    int i;
    for (i = 0; i < 32; i++) {
        uint8_t a = src1[i];
        uint8_t b = src2[i];
        uint16_t r = a + b;
        dst[i] = r & 0xff;
    }
}

void add_256bits_v2(uint8_t *dst, uint8_t *src1, uint8_t *src2)
{
    int i; uint8_t carry = 0;
    for (i = 0; i < 32; i++) {
        uint8_t a = src1[i];
        uint8_t b = src2[i];
        uint16_t r = (uint16_t) a + (uint16_t) b + (uint16_t) carry;
        dst[i] = r & 0xff;
        carry = (r >= 0x100) ? 1 : 0;
    }
}

void multiply8_v1(uint8_t *dst, uint8_t *src, int bytes)
{
    int i;
    uint8_t prev_acc = 0;
    for (i = 0; i < bytes; i++) {
        dst[i] = (src[i] << 3) + (prev_acc & 0x8);
        prev_acc = src[i] >> 5;
    }
}

void multiply8_v2(uint8_t *dst, uint8_t *src, int bytes)
{
    int i;
    uint8_t prev_acc = 0;
    for (i = 0; i < bytes; i++) {
        dst[i] = (src[i] << 3) + (prev_acc & 0x7);
        prev_acc = src[i] >> 5;
    }
    dst[bytes] = src[bytes-1] >> 5;
}

int cardano_crypto_ed25519_scalar_add(const ed25519_secret_key_64 sk1, const ed25519_secret_key_64 sk2, ed25519_secret_key_64 res)
{
    bignum256modm s1, s2;
    expand256_modm(s1, sk1, 32);
    expand256_modm(s2, sk2, 32);
    add256_modm(s1, s1, s2);
    contract256_modm(res, s1);
    return 0;
}

void scalar_add_no_overflow(const ed25519_secret_key_64 sk1, const ed25519_secret_key_64 sk2, ed25519_secret_key_64 res)
{
    uint16_t r = 0; int i;
    for (i = 0; i < 32; i++) {
        r = (uint16_t) sk1[i] + (uint16_t) sk2[i] + r;
        res[i] = (uint8_t) r;
        r >>= 8;
    }
}

void add_left(ed25519_secret_key_64 res_key, uint8_t *z, ed25519_secret_key_64 priv_key, derivation_scheme_mode mode)
{
    uint8_t zl8[32];

    memset(zl8, 0, 32);
    switch (mode) {
    case DERIVATION_V1:
        /* get 8 * Zl */
        multiply8_v1(zl8, z, 32);

        /* Kl = 8*Zl + parent(K)l */
        cardano_crypto_ed25519_scalar_add(zl8, priv_key, res_key);
        break;
    case DERIVATION_V2:
        /* get 8 * Zl */
        multiply8_v2(zl8, z, 28);
        /* Kl = 8*Zl + parent(K)l */
        scalar_add_no_overflow(zl8, priv_key, res_key);
        break;
    }
}

void add_right(ed25519_secret_key_64 res_key, uint8_t *z, ed25519_secret_key_64 priv_key, derivation_scheme_mode mode)
{
    switch (mode) {
    case DERIVATION_V1:
        add_256bits_v1(res_key + 32, z+32, priv_key+32);
        break;
    case DERIVATION_V2:
        add_256bits_v2(res_key + 32, z+32, priv_key+32);
        break;
    }
}

void serialize_index32(uint8_t *out, uint32_t index, derivation_scheme_mode mode)
{
    switch (mode) {
    case DERIVATION_V1: /* BIG ENDIAN */
        out[0] = index >> 24;
        out[1] = index >> 16;
        out[2] = index >> 8;
        out[3] = index;
        break;
    case DERIVATION_V2: /* LITTLE ENDIAN */
        out[3] = index >> 24;
        out[2] = index >> 16;
        out[1] = index >> 8;
        out[0] = index;
        break;
    }
}

void stretch(uint8_t *buf, uint32_t const buf_len, uint8_t const *pass, uint32_t const pass_len)
{
    const uint8_t salt[] = "encrypted wallet salt";
    assert(pass_len > 0);
    pbkdf2_hmac_sha512(pass, pass_len, salt, sizeof(salt), NB_ITERATIONS, buf, buf_len);
}


/* only 2 valids values are 256 (32) and 128 (16) */
void cryptonite_chacha_init_core(cryptonite_chacha_state *st,
                                 uint32_t keylen, const uint8_t *key,
                                 uint32_t ivlen, const uint8_t *iv)
{

    const char sigma[16] = "expand 32-byte k";
    const char tau[16] = "expand 16-byte k";

    const char *constants = (keylen == 32) ? sigma : tau;
//    const char *constants = (keylen == 32) ? "expand 32-byte k" : "expand 16-byte k";

    st->d[0] = U8TO32_LITTLE(constants + 0);
    st->d[1] = U8TO32_LITTLE(constants + 4);
    st->d[2] = U8TO32_LITTLE(constants + 8);
    st->d[3] = U8TO32_LITTLE(constants + 12);

    st->d[4] = U8TO32_LITTLE(key + 0);
    st->d[5] = U8TO32_LITTLE(key + 4);
    st->d[6] = U8TO32_LITTLE(key + 8);
    st->d[7] = U8TO32_LITTLE(key + 12);
    /* we repeat the key on 128 bits */
    if (keylen == 32)
        key += 16;
    st->d[8] = U8TO32_LITTLE(key + 0);
    st->d[9] = U8TO32_LITTLE(key + 4);
    st->d[10] = U8TO32_LITTLE(key + 8);
    st->d[11] = U8TO32_LITTLE(key + 12);
    st->d[12] = 0;
    switch (ivlen) {
    case 8:
        st->d[13] = 0;
        st->d[14] = U8TO32_LITTLE(iv + 0);
        st->d[15] = U8TO32_LITTLE(iv + 4);
        break;
    case 12:
        st->d[13] = U8TO32_LITTLE(iv + 0);
        st->d[14] = U8TO32_LITTLE(iv + 4);
        st->d[15] = U8TO32_LITTLE(iv + 8);
    default:
        return;
    }
}

void cryptonite_chacha_init(cryptonite_chacha_context *ctx, uint8_t nb_rounds,
                            uint32_t keylen, const uint8_t *key,
                            uint32_t ivlen, const uint8_t *iv)
{
    memset(ctx, 0, sizeof(*ctx));
    ctx->nb_rounds = nb_rounds;
    cryptonite_chacha_init_core(&ctx->st, keylen, key, ivlen, iv);
}

void memory_combine(uint8_t const *source, uint8_t *dest, uint32_t sz)
{
    memcpy(dest, source, sz);
}

void unencrypt_start
    (encrypted_key const *encrypted_key /* in */,
     ed25519_secret_key_64  decrypted_key /* out */)
{
    memory_combine(encrypted_key->ekey, decrypted_key, 64);
}

void unencrypt_stop(ed25519_secret_key_64 decrypted_key)
{
    clear(decrypted_key);
}

void wallet_encrypted_initialize
    (const ed25519_secret_key_64 secret_key,
     const uint8_t cc[CHAIN_CODE_SIZE],
     encrypted_key *encrypted_key)
{
    ed25519_public_key pub_key;

    ed25519_publickey(secret_key, pub_key);

    memory_combine(secret_key, encrypted_key->ekey, ENCRYPTED_KEY_SIZE);

    memcpy(encrypted_key->pkey, pub_key, PUBLIC_KEY_SIZE);
    memcpy(encrypted_key->cc, cc, CHAIN_CODE_SIZE);
}

void wallet_encrypted_derive_private
    (encrypted_key *in,
     uint32_t index,
     uint8_t *result,
     derivation_scheme_mode mode)
{

        ed25519_secret_key_64 res_key;
	ed25519_secret_key_64 priv_key;
        HMAC_SHA512_CTX hmac_ctx;
        uint8_t idxBuf[4];
        uint8_t z[64];
        uint8_t hmac_out[64];

	serialize_index32(idxBuf, index, mode);

	unencrypt_start(in, priv_key);

        uint8_t TAG_DERIVE_Z_NORMAL[32] = {0x2};
        uint8_t TAG_DERIVE_Z_HARDENED[32] = {0x0};
        uint8_t TAG_DERIVE_CC_NORMAL[32] = {0x3};
        uint8_t TAG_DERIVE_CC_HARDENED[32] = {0x1};

	/* calculate Z */
        hmac_sha512_Init(&hmac_ctx, in->cc, CHAIN_CODE_SIZE);
	if (index_is_hardened(index)) {
            hmac_sha512_Update(&hmac_ctx, TAG_DERIVE_Z_HARDENED, 1);
            hmac_sha512_Update(&hmac_ctx, priv_key, ENCRYPTED_KEY_SIZE);
	} else {
            hmac_sha512_Update(&hmac_ctx, TAG_DERIVE_Z_NORMAL, 1);
            hmac_sha512_Update(&hmac_ctx, in->pkey, PUBLIC_KEY_SIZE);
	}
        hmac_sha512_Update(&hmac_ctx, idxBuf, 4);
        hmac_sha512_Final(&hmac_ctx, z);

	add_left(res_key, z, priv_key, mode);
        add_right(res_key, z, priv_key, mode);

        /* calculate the new chain code */
        hmac_sha512_Init(&hmac_ctx, in->cc, CHAIN_CODE_SIZE);
        if (index_is_hardened(index)) {
            hmac_sha512_Update(&hmac_ctx, TAG_DERIVE_CC_HARDENED, 1);
            hmac_sha512_Update(&hmac_ctx, priv_key, ENCRYPTED_KEY_SIZE);
        } else {
            hmac_sha512_Update(&hmac_ctx, TAG_DERIVE_CC_NORMAL, 1);
            hmac_sha512_Update(&hmac_ctx, in->pkey, PUBLIC_KEY_SIZE);
        }
        hmac_sha512_Update(&hmac_ctx, idxBuf, 4);
        hmac_sha512_Final(&hmac_ctx, hmac_out);

        memcpy(result, res_key, 64);
        memcpy(result + 64, hmac_out + 32, 32);

        clear(priv_key);
        clear(idxBuf);
        clear(z);

        clear(hmac_out);
        clear(res_key);
        return;
}
