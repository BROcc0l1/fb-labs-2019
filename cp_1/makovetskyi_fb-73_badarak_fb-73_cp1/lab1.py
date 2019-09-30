import sys


def import_data(filepath):

	with open(filepath, 'r', encoding='utf-8') as data_source:

		return data_source.read()


def calculate_freq_letters(text): # TODO: calcularw frequency, not quantity

	freq = {}

	for letter in text:
		if letter in freq:
			freq[letter] += 1
		else:
			freq[letter] = 1

	return freq


def calculate_freq_bigrams(text): # TODO: calcularw frequency, not quantity

	freq = {}

	for i in range(len(text)-1):
		bigram = text[i:i+2]
		if bigram in freq:
			freq[bigram] += 1
		else:
			freq[bigram] = 1

	return freq



def calculate_entropy():

	pass


def calculate_redundancy():

	pass



def remove_spaces(text):

	return ''.join([letter for letter in text if letter != ' '])



def main():


	filepath = 'text_parsed.txt'


	data = import_data(filepath)


	freq_letters = calculate_freq_letters(data)

	print(freq_letters)

	freq_bigrams = calculate_freq_bigrams(data)

	print(freq_bigrams)

	no_space_text = remove_spaces(data)

	print(no_space_text)



main()