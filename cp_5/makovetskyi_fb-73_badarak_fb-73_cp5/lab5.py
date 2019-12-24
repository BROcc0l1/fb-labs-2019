import random
from math import gcd



def prime_by_miller_rabin(p, rounds=1024):

	# simple prime division tests
	primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 27, 29, 31, 37]

	if p in primes or p == 1:
		return True

	for pr in primes:
		if p % pr == 0:
			print('div')
			return False

	d = p - 1
	s = 0

	while  d % 2 == 0:
		d //= 2
		s += 1

	for i in range(rounds):
		
		x = random.randrange(2, p)

		if gcd(x, p) > 1:
			print('T-1')
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
				print('T-2')
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
		print(p)
		if prime_by_miller_rabin(p):
			return p
		else:
			return create_random_prime(min, max)




		

#print(prime_by_miller_rabin(7571, 128))
create_random_prime(1, 10000)