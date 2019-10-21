import os


ALPHABET = 'абвгдежзийклмнопрстуфхцчшщыьэюя'

ALPHABET_DICT = {
	'а': 0, 'б': 1, 'в': 2, 'г': 3, 'д': 4, 'е': 5, 'ж': 6,
	'з': 7, 'и': 8, 'й': 9, 'к': 10, 'л': 11, 'м': 12,
	'н': 13, 'о': 14, 'п': 15, 'р': 16, 'с': 17, 'т': 18,
	'у': 19, 'ф': 20, 'х': 21, 'ц': 22, 'ч': 23, 'ш': 24, 
	'щ': 25, 'ы': 26, 'ь': 27, 'э': 28, 'ю': 29, 'я': 30
}

KEYS_DICT = {
	2: 'ор',
	3: 'рик',
	4: 'кусь',
	5: 'морти',
	12: 'велоцераптор'
}



def import_data(filepath):

	with open(filepath, 'r', encoding='utf-8') as data_source:
		return data_source.read()


def vigenere_encrypt(plaintext, key, alphabet_dict):

	reverse_alphabet_dict = {val: let for let, val in alphabet_dict.items()}
	period = len(key)
	ciphertext = ''

	for s in range(len(plaintext)):

		pt_value = alphabet_dict[plaintext[s]]

		key_value = alphabet_dict[key[s % period]]

		ct_value = (pt_value + key_value) % len(alphabet_dict)

		ciphertext += reverse_alphabet_dict[ct_value]
	
	return ciphertext


def vigenere_encrypt_lab(filepath, keys, alphabet_dict):

	plaintext = import_data(filepath)

	for key in keys:

		output_file_path = os.path.splitext(filepath)[0] + '_encrypted_keylen_' + str(key) + '.txt'

		with open(output_file_path, 'w', encoding='utf-8') as output_file:
			
			output_file.write(vigenere_encrypt(plaintext, keys[key], alphabet_dict))
			
			



def main():

	global ALPHABET
	global ALPHABET_DICT
	global KEYS_DICT

	plaintext = import_data('TEXT_parsed.txt')

	#print(plaintext)

	#print(vigenere_encrypt('броварысело', 'город', ALPHABET_DICT))
	#print(vigenere_encrypt(plaintext, KEYS_DICT[4], ALPHABET_DICT))

	vigenere_encrypt_lab('TEXT_parsed.txt', KEYS_DICT, ALPHABET_DICT)	



main()