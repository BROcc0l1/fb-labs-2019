from collections import Counter
import re


with open('crackme.txt') as f:  
	data = f.read()
data = data.replace("\n","") #чтобы убрать символы новой строки 

with open('wind.txt') as f:  
	opentext0 = f.read()

res = Counter(opentext0)
sum = 0
for value in res.values():
	sum += value*(value-1)
l = len(opentext0)
I = sum / (l*(l-1))
print('Индекс открытого текста: ', I)

def filtration(text):
	text = text.lower() #все на строчные
	text = re.sub(r'[^а-яё\s]', '', text) #все, что не русские буквы и пробел убираем
	text = re.sub( '\s+', ' ',text )  #заменяет несколько пробелов на один
	return text

opentext = filtration(opentext0)
opentext = opentext.replace(' ', '')
opentext = opentext.replace('ё', 'е')


def encrypt(key0):
	
	N = int(len(opentext) / len(key0))
	l = len(opentext) % len(key0)
	key = key0*N + key0[:l]
	#print(len(opentext), len(key))
	letters = ['а', 'б', 'в', 'г', 'д', 'е', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ','ы', 'ь', 'э','ю','я']
	numbers = [i for i in range (0,33)]
	alph = dict(zip(letters, numbers))


	int_open = [alph.get(character) for character in opentext] #перевели открытый текст в номер позиции
	int_key = [alph.get(character) for character in key] #перевели ключ в номера

	#print(len(int_open), len(int_key))

	ciphertext = []
	for i in range(len(int_open)):
		y = (int_open[i] + int_key[i])%32
		ciphertext.append(y)
	num_alph = {v: k for k, v in alph.items()}
	ciphertext = ''.join([num_alph.get(character) for character in ciphertext])
	print(ciphertext[:50])

	my_file = open("key{}.txt".format(len(key0)), "w")
	my_file.write(ciphertext)
	my_file.close()

	r = len(key0)

	Y =  ciphertext #каждый r-ый символ


	res = Counter(Y)
	print(res)

	sum = 0
	for value in res.values():
		sum += value*(value-1)
	l = len(Y)
	I = sum / (l*(l-1))
	print("Индекс совпадений на длине {} : {}".format(r, I) )

#key2 	
encrypt('да')
#key3
encrypt('кот')
#key4
encrypt('день')
#key5
encrypt('жизнь')
#key10
encrypt('могущество')
#key11
encrypt('первородный')
#key12
encrypt('гигантомания')
#key13
encrypt('исследователь')
#key14
encrypt('кровьпламятрон')
#key15
encrypt('танецльдаипламя')
#key16
encrypt('ирландиятрольэль')
#key17
encrypt('агробактериология')
#key18
encrypt('макроэкономический')
#key19
encrypt('многофункциональный')
#key20
encrypt('нейролингвистический')

#Decryoting part

from collections import Counter
import re

with open('crackme.txt') as f:  
	data = f.read()
data = data.replace("\n","") #чтобы убрать символы новой строки 

Indices = []

for r in range(2, 31):  #период, длина ключа

	Y =  data[::r] #каждый r-ый символ
	#print(Y)

	res = Counter(Y)
	#print(res)
	sum = 0
	for value in res.values():
		sum += value*(value-1)
	l = len(Y)
	I = sum / (l*(l-1))
	Indices.append(I)
	print("Индекс совпадений на длине {} : {}".format(r, I) )

letters = ['а', 'б', 'в', 'г', 'д', 'е', 'ж', 'з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ','ы', 'ь', 'э','ю','я']
numbers = [i for i in range (0,33)]
alph = dict(zip(letters, numbers))

num_alph = {v: k for k, v in alph.items()}

len_key = 14

general = ''

for i in range(len_key):
	Yi = data[i::14]
	letter = Counter(Yi).most_common(1)[0][0]
	int_let = alph.get(letter)
	k = (int_let - 14)%32
	open_letter = num_alph.get(k)
	general += open_letter

print(general)

key0 = 'чугунныенебеса'
#Ci = (Pi + 34 - Kj) mod 33

N = int(len(data) / len(key0))
l = len(data) % len(key0)
key = key0*N + key0[:l]

int_data = [alph.get(character) for character in data] #перевели открытый текст в номер позиции
int_key = [alph.get(character) for character in key] #перевели ключ в номера



opentext = []
for i in range(len(int_data)):
	y = (int_data[i] + 32 - int_key[i])%32
	opentext.append(y)
opentext = ''.join([num_alph.get(character) for character in opentext])
print(opentext[:50])
my_file = open("opentext.txt", "w")
my_file.write(opentext)
my_file.close()


confusion = opentext[1::14]
print(Counter(confusion))
confusion1 = opentext[12::14]
print(Counter(confusion1))