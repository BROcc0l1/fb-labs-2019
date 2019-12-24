import random
from math import gcd



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
		#print('Modular inverse for such values does not exist:', a1, 'mod', b1)
		#return False


def prime_by_miller_rabin(p, rounds=1024):

	# simple prime division tests
	primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 27, 29, 31, 37]

	if p in primes or p == 1:
		return True

	for pr in primes:
		if p % pr == 0:
			return False

	d = p - 1
	s = 0

	while  d % 2 == 0:
		d //= 2
		s += 1

	for i in range(rounds):
		
		x = random.randrange(2, p)

		if gcd(x, p) > 1:
			return False

		x = pow(x, d, p)

		if x in (1, p - 1):
			continue

		xr = x

		for r in range(1, s):
			xr = pow(xr, 2, p)
			if xr == p - 1:
				return True
			if xr == 1:
				return False

		if xr != p - 1:
			return False


	return True


def create_random_prime(min, max):

	x = random.randrange(min, max + 1)
	m0 = 0
	if x % 2 == 0:
		m0 = x + 1
	else:
		m0 = x

	#print(x, m0)

	for i in range((max - m0) // 2):
		p = m0 + 2 * i
		#print(p)
		if prime_by_miller_rabin(p):
			return p
		else:
			return create_random_prime(min, max)


def generate_RSA_key_pair(p, q):

	n = p * q
	eul = (p - 1) * (q - 1)

	e = create_random_prime(2, eul - 1)
	e = (2 ** 16) + 1

	while gcd(e, eul) != 1:
		e = create_random_prime(2, eul - 1)

	try:
		d = modular_inverse(e, eul) % eul
	except ValueError as ve:
		print(ve)

	return d, n, e


def RSA_encrypt(message, e, n):
	return pow(message, e, n)


def RSA_decrypt(ciphertext, d, n):
	return pow(ciphertext, d, n)


def RSA_sign(message, d, n):
	return message, pow(m, d, n)


def RSA_validate_signature(msg, sign, e, n):
	return True if msg == pow(sign, e, n) else False


# TODO: Add checking for n1 >= n
def RSA_send_key(e, n, d, e1, n1, k):
	
	k1 = pow(k, e1, n1)
	s1 = pow(s, e1, n1)
	s = pow(k, d, n)

	return k1, s1


def RSA_get_key(k1, d1, n1, s1, e, n, s):

	k = pow(k1, d1, n1)
	s = pow(s1, d1, n1)
	if RSA_validate_signature(k, s, e, n) == False:
		raise Exception('RSA key not validated!')


#print(prime_by_miller_rabin(7571, 128))
print(create_random_prime(1, 10000))


