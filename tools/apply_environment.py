import sys
import json

args = sys.argv
environment = args[1]

with open('registry.json') as file:
    data = json.load(file)

if environment == 'coldwallet_mainnet':
    for item in data:
        if item['id'] == 'classic':
            item['slip44'] = 60
            for derivation in item['derivation']:
                derivation['path'] = "m/44'/60'/0'/0/0"
            break
elif environment == 'coldwallet_testnet':
    for item in data:
        if item['id'] == 'classic':
            item['slip44'] = 60
            for derivation in item['derivation']:
                derivation['path'] = "m/44'/60'/0'/0/0"
        if item['id'] == 'bitcoin':
            item['p2pkhPrefix'] = 111
            item['p2shPrefix'] = 196
        if item['id'] == 'litecoin':
            item['p2pkhPrefix'] = 111
            item['p2shPrefix'] = 58
        if item['id'] == 'doge':
            item['p2pkhPrefix'] = 113
            item['p2shPrefix'] = 196
        if item['id'] == 'bitcoincash':
            item['p2pkhPrefix'] = 111
            item['p2shPrefix'] = 196
            item['hrp'] = 'bchtest'

with open('registry.json', 'w') as outfile:
    json.dump(data, outfile, indent=2)
