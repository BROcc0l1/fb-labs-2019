import random
from math import gcd



def prime_by_miller_rabin(p, rounds):

	# simple prime division tests
	primes = [2, 3, 5, 7, 13, 17, 19, 23, 27, 29, 31, 37]

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

		if x in (1, -1):
			return True

		for r in range(1, s):
			xr = pow(x, 2**r, p)
			if xr == -1:
				return True
			elif xr == 1:
				return False


		return True

			
#print(prime_by_miller_rabin(1299827, 128))

# TODO: finish this 
def create_random_number(min, max):

	x = random.randrange(min, max)
	m0 = 0
	if x % 2 == 0:
		m0 = x + 1
	else:
		m0 = x

	print(x, m0)

	for i in range((max - m0) // 2):

		p = m0 + 2 * i
		if prime_by_miller_rabin(p, 1024):
			return p
		


print(create_random_number(1, 10))