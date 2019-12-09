# var2
from collections import deque

p1 = (1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0)
p2 = (1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0)


def lfsr(poly, outputfile):

	register = deque()

	result = []
	period = 0

	# Initialize register state (impulse function)
	for i in range(len(poly) - 1):
		register.append(0)
	register.append(1)

	start_state = register.copy()

	while True:

		temp = register[0] * poly[0]

		for i in range(1, len(register)):
			temp = temp ^ (register[i] * poly[i])

		result.append(register.popleft())
		period += 1

		register.append(temp)

		if register == start_state:

			with open(outputfile, 'w', encoding='utf-8') as f:
				for i in result:
					f.write(str(i))
			print("LFSR result written to " + outputfile)

			return period


def ngram_count(text, ngram_len): # How should i count it???

	ngram_count = {}

	for i in range(len(text) - ngram_len + 1):

		ngram = text[i : i + ngram_len]

		try:
			ngram_count[ngram] += 1
		except:
			ngram_count[ngram] = 1

	return ngram_count


def autocorrelation(arr, period, d):

	sum = 0

	for i in range(period):

		sum += (int(arr[i]) + int(arr[(i + d) % period])) % 2

	return sum


def ngram_count_task(text, max_len, filename):

	with open(filename, 'w', encoding='utf-8') as f:

		for length in range(1, max_len + 1):

			f.write('Ngram length: ' + str(length) + '\n')
			f.write('Ngrams:\n' + str(ngram_count(text, length)) + '\n\n')

	print('Ngrams count written to ' + filename)


def autocorrelation_task(arr, period):

	res = {}
	for d in range(11):
		res[d] = autocorrelation(arr, period, d)
		print('autocorrelation for d=' + str(d) + ':', autocorrelation(arr, period, d))
	return res


def import_data(filename):
	with open(filename, 'r', encoding='utf-8') as f:
		return f.read()



def main():

	print('\n==== POLYNOM 1 ====\n')
	period1 = lfsr(p1, 'LFSR_result1.txt')

	print('Period:', period1)

	data1 = import_data('LFSR_result1.txt')

	#print(ngram_count(data1, 2))

	autocorrelation_task(data1, period1)
	ngram_count_task(data1, len(p1), 'L1_ngrams.txt')


	print('\n==== POLYNOM 2 ====\n')

	period2 = lfsr(p2, 'LFSR_result2.txt')

	print('Period:', period2)

	data2 = import_data('LFSR_result2.txt')

	#print(ngram_count(data1, 2))

	autocorrelation_task(data2, period2)
	ngram_count_task(data2, len(p2), 'L2_ngrams.txt')



main()