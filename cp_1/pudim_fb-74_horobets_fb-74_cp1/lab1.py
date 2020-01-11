'''TO DO:
- filtration
- freq of symbols
- freq of bigrams
	-with step 1
	- with step 2
- H1
- H2
- counts
'''
from collections import Counter 


f = open("text1.txt", "r")
text1 = f.read()
#res1 = Counter(text1)
#print(res1)

import re
import numpy as np

def filtration(text):
	text = text.lower() #все на строчные
	text = re.sub(r'[^а-яё\s]', '', text) #все, что не русские буквы и пробел убираем
	text = re.sub( '\s+', ' ',text )  #заменяет несколько пробелов на один
	return text

print('With spaces:')

text2 = filtration(text1)
res2 = Counter(text2)
for key in res2:
	res2[key] /= len(text2)
print(res2)
h1 = 0
for key in res2:
	h1 += -res2[key]*np.log2(res2[key])
print(h1)
print(1 - (h1/5))

bigrams_step1 = [text2[i:i+2] for i in range(0, len(text2), 1)]
res3 = Counter(bigrams_step1)
h2 = 0
for key in res3:
	p = res3[key] / sum(res3.values())
	h2 -= p * np.log2(p)
h2 = h2/2
print('Entropy bigrams with step1')
print(h2)
print(1 - (h2/5))

bigrams_step2 = [text2[i:i+2] for i in range(0, len(text2), 2)]
res3 = Counter(bigrams_step2)
h2 = 0
for key in res3:
	p = res3[key] / sum(res3.values())
	h2 -= p * np.log2(p)
h2 = h2/2
print('Entropy bigrams with step2')
print(h2)
print(1 - (h2/5))

alphabet = ['а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я', ' ']
leng = sum(res3.values())
for key in res3:
	p = res3[key] / leng
	res3[key] = '{:05.4f}'.format(p)
print(res3['аа'])

for i in alphabet:
	print(i, end = ' ')	
	for j in alphabet:
		if (i+j) in res3:
			print(res3[(i+j)], end=' ')
		else:
			print('0.0000', end=' ')
	print('\n')
print(res3['аа'])

'''----------------------------------------------------'''

print('Without spaces')
text2 = text2.replace(' ', '')
res2 = Counter(text2)
for key in res2:
	res2[key] /= len(text2)
print(res2)
h1 = 0
for key in res2:
	h1 += -res2[key]*np.log2(res2[key])
print('Entropy in monogram')
print(h1)
print(1 - (h1/5))

bigrams_step1 = [text2[i:i+2] for i in range(0, len(text2), 1)]
res3 = Counter(bigrams_step1)
h2 = 0
for key in res3:
	p = res3[key] / sum(res3.values())
	h2 -= p * np.log2(p)
h2 = h2/2
print('Entropy bigrams with step1')
print(h2)
print(1 - (h2/5))

bigrams_step2 = [text2[i:i+2] for i in range(0, len(text2), 2)]
res3 = Counter(bigrams_step2)
h2 = 0
for key in res3:
	p = res3[key] / sum(res3.values())
	h2 -= p * np.log2(p)
h2 = h2/2
print('Entropy bigrams with step2')
print(h2)
print(1 - (h2/5))

#print(len(set(key[0] for key in res3.keys())))
'''
for i in range(32):
	for j in range(32):
		print('{}{}'.format(i,j), end=' ')
	print('\n')
'''

alphabet = ['а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я']
leng = sum(res3.values())
for key in res3:
	p = res3[key] / leng
	res3[key] = '{:05.4f}'.format(p)
print(res3['аа'])

for i in alphabet:
	print(i, end = ' ')	
	for j in alphabet:
		if (i+j) in res3:
			print(res3[(i+j)], end=' ')
		else:
			print('0.0000', end=' ')
	print('\n')
print(res3['аа'])
