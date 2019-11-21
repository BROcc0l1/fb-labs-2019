# Variant 11

ALPHABET = 'абвгдежзийклмнопрстуфхцчшщыьэюя'

ALPHABET_DICT = {
	'а': 0, 'б': 1, 'в': 2, 'г': 3, 'д': 4, 'е': 5, 'ж': 6,
	'з': 7, 'и': 8, 'й': 9, 'к': 10, 'л': 11, 'м': 12,
	'н': 13, 'о': 14, 'п': 15, 'р': 16, 'с': 17, 'т': 18,
	'у': 19, 'ф': 20, 'х': 21, 'ц': 22, 'ч': 23, 'ш': 24, 
	'щ': 25, 'ы': 26, 'ь': 27, 'э': 28, 'ю': 29, 'я': 30
}

THEORETICAL_MOST_FREQUENT_BIGRAMS = ['ст', 'но', 'то', 'на', 'ен']

PRACTICAL_MOST_FREQUENT_BIGRAMS = ['нк', 'юж', 'хб', 'шь', 'мк']
PRACTICAL_MOST_FREQUENT_BIGRAMS_DICT = {'нк': 0.014594735470419598, 'юж': 0.013552254365389628, 'хб': 0.012770393536617148, 'шь': 0.012770393536617148, 'мк': 0.012249152984102164}
PR_WITH_NEWLINE = {'шь': 0.008515030318668558, 'мк': 0.008515030318668558, 'ьх': 0.007740936653335054, 'хб': 0.007224874209779383, 'нк': 0.006966842988001548}


def import_data(filename):

	with open(filename, 'r') as f:

		return f.read()


def bigram_to_int(bigram):

	global ALPHABET_DICT

	splitted = list(bigram)

	bigram_num = ALPHABET_DICT[splitted[0]] * len(ALPHABET_DICT) + ALPHABET_DICT[splitted[1]]

	return(bigram_num)


def int_to_bigram(number):

	global ALPHABET_DICT

	rev = {val: let for let, val in ALPHABET_DICT.items()}

	bigram_first = number // len(ALPHABET_DICT)
	bigram_second = number % len(ALPHABET_DICT)

	return rev[bigram_first] + rev[bigram_second]


def gcd(a, b):

	if b == 0:
		return a
	else:
		return gcd(b, a % b)


def modular_inverse(a, b):

	x, y = 0, 1
	u, v = 1, 0
	m = b
	a1 = a
	b1 = b

	while a != 0:

		q = b // a
		r = b % a

		m = x - u * q
		n = y - v * q

		b,a, x,y, u,v = a,r, u,v, m,n

	gcd = b

	if x < 0:
		x += m

	if gcd == 1:
		return x
	else:
		raise ValueError('Modular inverse for such values does not exist:', a1, b1)


# Solve linear equasion:
# ax = b mod n
def solve_linear_equasion(a, b, n):
	#print(a, n, '<<<')

	gcd_val = gcd(a, n)

	if gcd_val == 1:

		x = (b * modular_inverse(a, n)) % n

		return [x]

	elif gcd_val > 1:

		if b % gcd_val != 0:
			raise ValueError('The equasion has no solutions.')

		if b % gcd_val == 0:

			pass


def check_text_reality(text): # TODO: finish and improve

	# Filtering using forbidden bigrams criterium

	forbidden_bigrams = [
		'аь', 'оь', 'уь', 'ыь', 'эь', 'иь', 'еь', 'яь', 'йь'
		'аъ', 'оъ', 'уъ', 'ыъ', 'эъ', 'иъ', 'еъ', 'яъ', 'йъ'
		'ъъ', 'ыы', 'ьь', 'йй']

	for b in forbidden_bigrams:
		if b in text:
			return False


	# Filtering using monogram frequencies

	pass


	# Filtering using bigram frequencies

	pass
	

	return True


def get_all_bigrams_pairs(arr):

	res = []
	print(type(arr))

	# Find all possible practical pairs
	for i in range(len(arr)):
		# fix one of the items and add all others
		for j in range(len(arr)):
			# Do not pair a bigram with itself
			if i != j:
				res.append((arr[i], arr[j]))

	return res


def find_key(theor_bigram_pair, encr_bigram_pair):

	# Y1 - Y2 = a(X1 - X2) (mod m**2)

	global ALPHABET_DICT

	m = len(ALPHABET_DICT)

	theor_diff = (bigram_to_int(theor_bigram_pair[0]) - bigram_to_int(theor_bigram_pair[1])) % m
	encr_diff = (bigram_to_int(encr_bigram_pair[0]) - bigram_to_int(encr_bigram_pair[1])) % m
	#print(encr_diff, '######')
	
	le_solutions = solve_linear_equasion(encr_diff, theor_diff, m)

	res = []

	for a  in le_solutions:
		a = a % m**2
		b = (bigram_to_int(theor_bigram_pair[0]) - a * bigram_to_int(encr_bigram_pair[0])) % m**2
		res += [a, b]

	return res


def attack_affine(theoretical, practical):

	all_lang = get_all_bigrams_pairs(theoretical)
	all_encr = get_all_bigrams_pairs(practical)

	res = []

	# Match all bigrams in language to the ones in ciphertext
	# and find the keys for them
	for i in range(len(all_lang)):
		for j in range(len(all_encr)):

				key = find_key(all_lang[i], all_encr[i])

	print(key)




def main():

	global THEORETICAL_MOST_FREQUENT_BIGRAMS
	global PRACTICAL_MOST_FREQUENT_BIGRAMS

	plaintext = import_data('11.txt')

	print(attack_affine(THEORETICAL_MOST_FREQUENT_BIGRAMS, PRACTICAL_MOST_FREQUENT_BIGRAMS))



#print(get_all_bigrams_pairs(['аб','вг','де']))
main()