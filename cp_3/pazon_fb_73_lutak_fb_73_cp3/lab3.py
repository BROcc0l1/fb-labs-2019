import collections
import detectRussian
from math import *
bigramms_frequent = ['но', 'ст', 'ен', 'то', 'на']
bigrams_unexistant = ['иь', 'аь', 'оь', 'уь', 'еь', 'ыь', 'эь', 'яь', 'юь', 'йь', 'йй', 'ьь', 'ыы']
dict = open("alphabet.txt", 'r+', encoding='utf8', errors='ignore')
file_for_bi = open("15.txt", 'r+', encoding='utf8', errors='ignore')
dictionary = dict.read()
bigramms = []
def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, x, y = egcd(b % a, a)
        xx = y - (b // a) * x
        return (g, xx, x)
 
# x = mulinv(b) mod n, (x * b) % n == 1

def mulinv(b, n):
    g, x, _ = egcd(b, n)
    print(x)
    if g == 1:
        return x % n
file = file_for_bi.readline()
alphabet_bi={}    
def count_bigramms(file):
	length = 0
	for i in range(1,len(file)):
		bigram = file[i-1]+file[i]
		if bigram  in alphabet_bi:
			alphabet_bi[bigram]+=1;
			length = length +1
		else:
			alphabet_bi[bigram]=1;
			length = length +1
	return length;
length = count_bigramms(file)
#file_for_bi.close()
def sort_dictionary_by_value(dictionary):
    list_of_sorted_pairs = [(k, dictionary[k]) for k in sorted(dictionary.keys(), key=dictionary.get, reverse=True)]
    # Так мы создаём кортежи (ключ, значение) из отсортированных элементов по ключу равному "значение ключа"
    # Также отсортированы будут и ключи, имеющие одно значение
    # "reverse = False" говорит, что перебор нужно делать в обычном порядке
    # Если нужно отсортировать значения в обратном порядке, то reverse можно сделать = True
    return list_of_sorted_pairs 
new_a = sort_dictionary_by_value(alphabet_bi)

for x in new_a:
    print(x[0], x[1] )
    
###print(alphabet_bi)  
    
bigram_and_numbers = {}
def bigramm_number():
    i=0
    j=0
    for i in range(0,len(dictionary)):
            for j in range(0,len(dictionary)):
                bigramm = dictionary[i] + dictionary[j]
                bigramm_num = 31*i + j
                bigram_and_numbers[bigramm] = int(bigramm_num)
    ###print(bigram_and_numbers)
qwe = bigramm_number()

qw = [bigram_and_numbers.get('ст'), bigram_and_numbers.get('но'), bigram_and_numbers.get('ен'), bigram_and_numbers.get('то'), bigram_and_numbers.get('на')]
qwe11 = bigram_and_numbers.get('ыу')
qw2 = [bigram_and_numbers.get('ст'), bigram_and_numbers.get('но'), bigram_and_numbers.get('ен'), bigram_and_numbers.get('то'), bigram_and_numbers.get('на')]
qwe13 = bigram_and_numbers.get('юк')
print(qw)
print(qw2)
print(qwe11)
print(qwe13)
aaa = bigram_and_numbers.get('як')
aaa1 = bigram_and_numbers.get('ую')
aaa2 = bigram_and_numbers.get('ып')

def Common(a, b):
    if a > b:
        a, b = b, a
    list = [str(c) for c in range(2, b + 1) if not b % c and not a % c]
    if not list:
        print("Число не имеет общих делителей.")
        deliteli = False
        return deliteli
    else:
        deliteli = (', '.join(list))
        print(deliteli)
        return deliteli

def proverka(x,y):
    nsd, x_reversed, imp = egcd(x, 961)
    nsd1 = egcd(y,961)[1]
    nsd2 = egcd(x,y)[1]
    common1 = Common(int(x),int(y))
    common2 = Common(int(y),961)
    common3 = Common(int(x), 961)
    obshie = ''
    obshie1 = ''
    if nsd != 0:
        for i in common1:
            for j in common2:
                if int(i)==int(j):
                    obshie = obshie + i
                else:
                    resultat = False
                    return resultat
        for t in common3:
            for p in obshie:
                if int(t)==int(p):
                    obshie1 = obshie1 + t
                    resultat = max(obshie1)
                    return resultat
                else:
                    resultat = False
                    return resultat
    else:
        resultat = 1
        return resultat
a_list = ''
b list = ''        
def equation(x1,y1,x2,y2):
    x = (x1-x2)%961
    y = (y1-y2)%961
    nsd, x_reversed, imp = egcd(x, 961)
    per1 = proverka(x,y)
    if per1 != 0 and per1 != 1:
        m = 961/per1
        x = x/per1
        y = y/per1
        x_reversed = egcd(x,m)[2]
        print(str(y) + ' y value')
        print(str(x_reversed) + ' x^-1 value')
        a = (y*x_reversed)%961
        b = (y1-a*x1)%961
        for n in range(1, int(per1)):
            a_list.append(a)
            a = a+m
        for a in a_list:   
            b_list.append(b)        
            b = (y1-a*x1)%961
        return a_list,b_list
    elif per1 == 0:
        break
    else:
        print(str(y) + ' y value')
        print(str(x_reversed) + ' x^-1 value')
        a = (y*x_reversed)%961
        b = (y1-a*x1)%961
        return a,b 


def get_key(d, value):
            for k, v in d.items():
                if v == value:
                    return k

def decipher(a1,b1):
    i=0
    while i < len(file)-1:
        bigram = file[i]+file[i+1]
        i+=2
        bigram_value = bigram_and_numbers.get(bigram)
        a_rev= egcd(a1,961)[1]%961
        bigram_value_deciphered=((bigram_value-b1)*a_rev)%961
        print(bigram_value_deciphered)
        
        bigram_deciphered = get_key(bigram_and_numbers ,bigram_value_deciphered)
        print(bigram_deciphered, end='')      
for i in qw:
    for j in qw2:
       
                if i!=j:
                    print(str(i)+ ' ' + str(j) + ' possible opentext bigrams')
                    q = equation(i, qwe11, j, aaa)
                    result = decipher(q[0],q[1])
                    if detectRussian.isRussian(result, wordPercentage=50, letterPercentage=85):
                        print(result)
            
                    

