import sys
import math



'''
а б в г д е ж з и й к л м н о п р с т у ф х ц ч ш щ в ь э ю я

31
'''



def import_data(filepath):

	with open(filepath, 'r', encoding='utf-8') as data_source:

		return data_source.read()


def freq_by_number(numbers_dict, text_length):

	for key in numbers_dict.keys():
		numbers_dict[key] = numbers_dict[key] / text_length

	return numbers_dict


def calculate_freq_letters(text):
	freq = {}

	for letter in text:
		if letter in freq:
			freq[letter] += 1
		else:
			freq[letter] = 1

	return freq_by_number(freq, len(text))


def calculate_freq_bigrams(text):

	freq = {}

	for i in range(len(text)-1):
		bigram = text[i:i+2]
		if bigram in freq:
			freq[bigram] += 1
		else:
			freq[bigram] = 1

	return freq_by_number(freq, len(text))


def calculate_entropy(freq_dict):

	entropy = 0
	for i in freq_dict.values():
		entropy += i * math.log(i, 2)

	return -entropy


def print_frequencies(freq):

	sum = 0
	for key, value in sorted(freq.items()):
		print(key, '\t', value)
		sum += value
	print(sum)


def data_remove_spaces(text):

	return ''.join([letter for letter in text if letter != ' '])



def main():


	filepath = 'text_parsed.txt'


	data = import_data(filepath)


	#
	# Text with spaces
	#

	freq_letters = calculate_freq_letters(data)
	freq_bigrams = calculate_freq_bigrams(data)

	print_frequencies(freq_letters)
	#print_frequencies(freq_bigrams)

	entropy_letters = calculate_entropy(freq_letters)
	entropy_bigrams = calculate_entropy(freq_bigrams)
	print(entropy_letters, entropy_bigrams)


	# 
	# Text without spaces
	#

	no_space_text = data_remove_spaces(data)

	freq_letters_nospace = calculate_freq_letters(no_space_text)
	freq_bigrams_nospace = calculate_freq_bigrams(no_space_text)

	print_frequencies(freq_letters_nospace)
	#print_frequencies(freq_bigrams_nospace)

	entropy_letters_nospace = calculate_entropy(freq_letters_nospace)
	entropy_bigrams_nospace = calculate_entropy(freq_bigrams_nospace)
	print(entropy_letters_nospace, entropy_bigrams_nospace)



main()