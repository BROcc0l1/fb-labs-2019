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
	9: 'автопилот',
	12: 'велоцераптор',
	15: 'астроориентация'
}

THEORETICAL_FREQUENCES = {'ч': 0.015034171004991752, 'у': 0.029795188208325298, 'ж': 0.011383193721390263, 
'о': 0.11560475894623333, 'й': 0.010619077204333326, 'м': 0.03125914975969607, 'и': 0.06689054566488849, 
'р': 0.041951425041597934, 'е': 0.08193364326470567, 'т': 0.06399297298455342, 'л': 0.049303368539823325, 
'я': 0.023675114796009453, 'п': 0.026886903614199712, 'ш': 0.010020995351029415, 'в': 0.03993222929208532, 
'к': 0.03429062136241261, 'с': 0.05151716405653034, 'н': 0.0644642971913362, 'а': 0.08244960044561561, 
'б': 0.016871264220065556, 'ы': 0.02083824296048732, 'г': 0.016869478901100472, 'ю': 0.0064396455070662925, 
'щ': 0.0035456434646613964, 'д': 0.029977290742764104, 'ь': 0.022491448322157236, 'х': 0.008805193135805644, 
'з': 0.016833772521798743, 'ц': 0.0030957430854596482, 'э': 0.0028065214131156673, 'ф': 0.00042133527576036734}


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


def calculate_ICs(text, alphabet_dict):

	res_dict = {}

	for block_len in range(2, 31):

		ic_sum = 0
		

		for i in range(block_len):
			seq = ''
			for j in range(i, len(text), block_len):
				seq += text[j]
		
			ic_sum += calculate_index_of_coinsidence(seq, alphabet_dict)

		res = ic_sum / block_len
		print(block_len, res)
		res_dict[block_len] = res

		create_IC_csv(res_dict)

	pass

	return res_dict


def create_IC_csv(IC_dict):

	with open('IC.csv', 'w') as of:

		for key, value in IC_dict.items():

			of.write('{},{}\n'.format(key, value))



def main():

	global ALPHABET
	global ALPHABET_DICT
	global KEYS_DICT
	global THEORETICAL_FREQUENCES

	plaintext = import_data('TEXT_parsed.txt')
	ciphertext = import_data('ciphertext_var11_parsed.txt')

	vigenere_encrypt_lab('TEXT_parsed.txt', KEYS_DICT, ALPHABET_DICT)	

	ciphertext_2 = import_data('TEXT_parsed_encrypted_keylen_2.txt')
	ciphertext_3 = import_data('TEXT_parsed_encrypted_keylen_3.txt')
	ciphertext_4 = import_data('TEXT_parsed_encrypted_keylen_4.txt')
	ciphertext_5 = import_data('TEXT_parsed_encrypted_keylen_5.txt')
	ciphertext_9 = import_data('TEXT_parsed_encrypted_keylen_9.txt')
	ciphertext_12 = import_data('TEXT_parsed_encrypted_keylen_12.txt')
	ciphertext_15 = import_data('TEXT_parsed_encrypted_keylen_15.txt')

	texts = {0: plaintext, 2: ciphertext_2, 3: ciphertext_3, 4: ciphertext_4, 5: ciphertext_5, 9: ciphertext_9, 12: ciphertext_12, 15: ciphertext_15}
	indexes_of_coinsidence = {key: calculate_index_of_coinsidence(text, ALPHABET_DICT) for key, text in texts.items()}

	theoretical_ic = sum([p*p for p in THEORETICAL_FREQUENCES.values()])


	print(theoretical_ic, '\n')
	'''
	for i, j in indexes_of_coinsidence.items():
		print('{:>2} {:.6f}'.format(i, j))
	'''

	#find_key_length(plaintext, ALPHABET_DICT)
	
	csv = calculate_ICs(ciphertext, ALPHABET_DICT)

	create_IC_csv(csv)

main()