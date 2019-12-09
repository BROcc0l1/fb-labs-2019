# var2
from collections import deque
from collections import Counter
p1 = (1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1)
p2 = (1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0)

arr1 = [1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0]
arr2 = [1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0]


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

		#print(register)

		a = register.popleft()
		result.append(a)
		period += 1

		register.append(temp)

		if register == start_state:

			print(register)

			with open(outputfile, 'w', encoding='utf-8') as f:
				for i in result:
					f.write(str(i))
			print("LFSR result written to " + outputfile)

			return period


def ngram_count(text, ngram_len):

	ngram_count = {}

	for i in range(len(text) - ngram_len + 1):

		ngram = int(text[i : i + ngram_len])

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

	for i in range(1, max_len + 1):
		pass


def autocorrelation_task(arr, period):

	res = []
	for d in range(11):
		res.append(autocorrelation(arr, period, d))
		print('autocorrelation for d =', d, autocorrelation(arr, period, d))
	return res


def import_data(filename):
	with open(filename, 'r', encoding='utf-8') as f:
		return f.read()


def main():

	#period1 = lfsr(arr1, 'lfsr_result1.txt')

	data1 = import_data('lfsr_result1.txt')

	#print(ngram_count(data1, 2))

	print(autocorrelation_task(data1, 1398101))#period1))


main()