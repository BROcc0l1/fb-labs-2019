import re
from math import log



'''
а б в г д е ж з и й к л м н о п р с т у ф х ц ч ш щ ы ь э ю я

31
'''



def import_data(filepath):

	with open(filepath, 'r', encoding='utf-8') as data_source:
		return data_source.read()


def freq_by_quantity(numbers_dict, text_length):

	for key in numbers_dict.keys():
		numbers_dict[key] = numbers_dict[key] / text_length

	return numbers_dict


def calculate_freq_ngrams(text, ngram_len=1, step=1):

	# Step MUST be less or equal to ngram length and more than zero
	# Ngram length must be greater than zero
	# Probably fix this later

	freq = {}

	for i in range(len(text)-ngram_len+1):
		ngram = text[i : i+ngram_len : step]
		if ngram in freq:
			freq[ngram] += 1
		else:
			freq[ngram] = 1

	return freq_by_quantity(freq, len(text))


def calculate_entropy(freq_dict, ngram_len=1):

	# Ngram length must be greater than zero
	# Probably fix this later

	entropy = 0
	for i in freq_dict.values():
		entropy += i * log(i, 2)

	return -entropy / ngram_len


def calculate_redundancy(entropy):

	pass


def print_frequencies(freq):

	sum = 0
	for key, value in sorted(freq.items()):
		print(key, '\t', value)
		sum += value
	print(sum)


def create_results_file(freq_letters, freq_bigrams,
                        entropy_letters, entropy_bigrams,
                        freq_letters_ns, freq_bigrams_ns,
                        entropy_letters_ns, entropy_bigrams_ns):

	res_file = open('lab1_results.txt', 'w+', encoding='utf-8')

	res_file.write('Letters entropy with spaces: {}\n'.format(entropy_letters))
	res_file.write('Letters entropy without spaces: {}\n\n'.format(entropy_letters_ns))
	res_file.write('Bigrams entropy with spaces: {}\n'.format(entropy_bigrams))
	res_file.write('Bigrams entropy without spaces: {}\n\n'.format(entropy_bigrams_ns))
	res_file.write('Frequency tables for all experiments are listed below.\n\n')

	res_file.write('|-----------------------------------------------|\n')
	res_file.write('|                    LETTERS                    |\n')
	res_file.write('|-----------------------------------------------|\n')
	res_file.write('|FREQUENCIES WITH SPACES|  FREQ WITHOUT SPACES  |\n')
	res_file.write('|-----------------------|-----------------------|\n')
	res_file.write('| ' + '_' + '     | ' + '{:.10f}'.format(freq_letters['_']) + '  |'
		  + '  SPACES ARE REMOVED   |\n')
	res_file.write('|-------|---------------|-----------------------|\n')

	for key, value in sorted(freq_letters.items()):
		if key != '_':
			res_file.write('| ' + key + '     | ' + '{:.10f}'.format(value) + '  | '
				  + key + '     | ' + '{:.10f}'.format(freq_letters_ns[key]) + '  |\n')
			res_file.write('|-------|---------------|-------|---------------|\n')
		
	res_file.write('|-----------------------------------------------|\n')
	res_file.write('|-----------------------------------------------|\n')
	res_file.write('|                    BIGRAMS                    |\n')
	res_file.write('|-----------------------------------------------|\n')
	res_file.write('|FREQUENCIES WITH SPACES|  FREQ WITHOUT SPACES  |\n')
	res_file.write('|-----------------------|-----------------------|\n')
	
	for key, value in sorted(freq_bigrams.items()):
		if '_' not in key:
			res_file.write('| ' + key + '    | ' + '{:.10f}'.format(value) + '  | '
				  + key + '    | ' + '{:.10f}'.format(freq_bigrams_ns[key]) + '  |\n')
			res_file.write('|-------|---------------|-------|---------------|\n')
		else:
			res_file.write('| ' + key + '    | ' + '{:.10f}'.format(value) + '  | '
				  + ' SPACES ARE REMOVED   |\n')
			res_file.write('|-------|---------------|-------|---------------|\n')

	res_file.close()


def data_remove_spaces(text):

	return ''.join([letter for letter in text if letter != ' '])



def main():


	filepath = 'text_parsed.txt'

	data = import_data(filepath)


	#
	# Text with spaces
	#

	replaced_spaces_text = re.sub(' ', '_', data) # Replace spaces for better readability 

	freq_letters = calculate_freq_ngrams(replaced_spaces_text)
	freq_bigrams = calculate_freq_ngrams(replaced_spaces_text, 2)

	#print_frequencies(freq_letters)
	#print_frequencies(freq_bigrams)

	entropy_letters = calculate_entropy(freq_letters)
	entropy_bigrams = calculate_entropy(freq_bigrams, 2)

	#print(entropy_letters, entropy_bigrams)


	# 
	# Text without spaces
	#

	no_space_text = data_remove_spaces(data)

	freq_letters_nospace = calculate_freq_ngrams(no_space_text)
	freq_bigrams_nospace = calculate_freq_ngrams(no_space_text, 2)

	#print_frequencies(freq_letters_nospace)
	#print_frequencies(freq_bigrams_nospace)

	entropy_letters_nospace = calculate_entropy(freq_letters_nospace)
	entropy_bigrams_nospace = calculate_entropy(freq_bigrams_nospace, 2)

	#print(entropy_letters_nospace, entropy_bigrams_nospace)

	create_results_file(freq_letters, freq_bigrams,
                        entropy_letters, entropy_bigrams,
                        freq_letters_nospace, freq_bigrams_nospace,
                        entropy_letters_nospace, entropy_bigrams_nospace)

	

main()