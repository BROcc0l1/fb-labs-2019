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
			
			
def calculate_index_of_coinsidence(text, alphabet_dict):

	n = len(text)
	res = 0
	letters_count = {}

	for letter in text:
		if letter in letters_count:
			letters_count[letter] += 1
		else:
			letters_count[letter] = 1

	for letter in letters_count:
		res += letters_count[letter] * (letters_count[letter] - 1)

	return res / (n * (n - 1))


def vigenere_decrypt(plaintext, key, alphabet_dict):

	reverse_alphabet_dict = {val: let for let, val in alphabet_dict.items()}
	period = len(key)
	plaintext = ''

	for s in range(len(plaintext)):

		ct_value = alphabet_dict[plaintext[s]]

		key_value = alphabet_dict[key[s % period]]

		pt_value = (ct_value - key_value) % len(alphabet_dict)

		plaintext += reverse_alphabet_dict[pt_value]

	return plaintext



def main():

	global ALPHABET
	global ALPHABET_DICT
	global KEYS_DICT

	plaintext = import_data('TEXT_parsed.txt')
	ciphertext = import_data('ciphertext_var11_parsed.txt')

	# vigenere_encrypt_lab('TEXT_parsed.txt', KEYS_DICT, ALPHABET_DICT)	

	ciphertext_2 = import_data('TEXT_parsed_encrypted_keylen_2.txt')
	ciphertext_3 = import_data('TEXT_parsed_encrypted_keylen_3.txt')
	ciphertext_4 = import_data('TEXT_parsed_encrypted_keylen_4.txt')
	ciphertext_5 = import_data('TEXT_parsed_encrypted_keylen_5.txt')
	ciphertext_12 = import_data('TEXT_parsed_encrypted_keylen_12.txt')

	plaintext_IC = calculate_index_of_coinsidence(plaintext, ALPHABET_DICT)
	ciphertext_2_IC = calculate_index_of_coinsidence(ciphertext_2, ALPHABET_DICT)
	ciphertext_3_IC = calculate_index_of_coinsidence(ciphertext_3, ALPHABET_DICT)
	ciphertext_4_IC = calculate_index_of_coinsidence(ciphertext_4, ALPHABET_DICT)
	ciphertext_5_IC = calculate_index_of_coinsidence(ciphertext_5, ALPHABET_DICT)
	ciphertext_12_IC = calculate_index_of_coinsidence(ciphertext_12, ALPHABET_DICT)

	print('{}\n{}\n{}\n{}\n{}\n{}\n'.format(
		plaintext_IC, ciphertext_2_IC, ciphertext_3_IC,
		ciphertext_4_IC, ciphertext_5_IC, ciphertext_12_IC))






main()