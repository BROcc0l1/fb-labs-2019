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

PRACTICAL_MOST_FREQUENT_BIGRAMS = {
	'хб': 0.007740936653335054, 
	'нк': 0.007224874209779383, 
	'бй': 0.0068378273771126305, 
	'юж': 0.006708811766223713, 
	'шь': 0.006321764933556961}


def bigram_to_int(bigram):

	global ALPHABET_DICT

	splitted = list(bigram)

	bigram_num = ALPHABET_DICT[splitted[0]] * len(ALPHABET_DICT) + ALPHABET_DICT[splitted[1]]

	return(bigram_num)


def int_to_bigram(number):

	global ALPHABET_DICT

	rev = {val: let for let, val in ALPHABET_DICT.items()}

	pass


def gcd(a, b):

	if b == 0:
		return a
	else:
		return gcd(b, a % b)


def modular_inverse(a, b):

	x, y = 0, 1
	u, v = 1, 0
	m = b

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
		raise ValueError('Modular inverse for such values does not exist.')


# Solve linear equasion:
# ax = b mod n
def solve_linear_equasion(a, b, n):

	gcd_val = gcd(a, n)

	if gcd_val == 1:

		x = (b * modular_inverse(a, n)) % n
		return list(x)

	elif gcd_val > 1:

		if b % d != 0:
			raise ValueError('The equasion has no solutions.')

		if b % d == 0:

			# d solutions
			x0 = solve_linear_equasion(a / gcd_val, b / gcd_val, x / gcd_val)
			res = []
			for i in range(d):
				res[i] = (n / gcd) * i + x0 % n

			return res


