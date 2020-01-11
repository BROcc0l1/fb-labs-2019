from math import log


alphabet_no_space = ['а','б','в','г','д','е','ё','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ь','ъ','ы','э','ю','я']
alphabet_wth_space = ['а','б','в','г','д','е','ё','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ь','ъ','ы','э','ю','я',' ']

input1 = open('D:/FIELS/CRYPT/LAB1/voina-i-mir_no_space.txt', 'r', encoding = 'utf-8')
input2 = open('D:/FIELS/CRYPT/LAB1/voina-i-mir_wth_space.txt', 'r', encoding = 'utf-8') 
a = input2.read()
c = input1.read()

'''
удаление спец символов

import re
s = a
reg = re.compile('[^а-яА-Я ]')
print(reg.sub('', s))

print(a.replace('ъ','ь')) замена ъ на ь
print(a.replace('ё','е')) замена ё на е
print(a.lower()) замена заглавных букв на строчные
print(c.replace(' ','')) удаление пробелов

'''
print('\n' + '=' * 120 + '\nMonograms\n\n' + '=' * 120 + '\nMonograms with spaces\n')

l = len(alphabet_wth_space)

for i in range(0, l):
	b = a.count(alphabet_wth_space[i])
	while i <= l:
		if b >= 1000:
			print(str(alphabet_wth_space[i]) + ' | ' + str(a.count(alphabet_wth_space[i])) + ' | ' + str((a.count(alphabet_wth_space[i])) / len(a)))
		elif b >= 100 and b <1000:
			print(str(alphabet_wth_space[i]) + ' | ' + str(a.count(alphabet_wth_space[i])) + '  | ' + str((a.count(alphabet_wth_space[i])) / len(a)))
		elif b >= 10 and b < 100:
			print(str(alphabet_wth_space[i]) + ' | ' + str(a.count(alphabet_wth_space[i])) + '   | ' + str((a.count(alphabet_wth_space[i])) / len(a)))
		else: 
			print(str(alphabet_wth_space[i]) + ' | ' + str(a.count(alphabet_wth_space[i])) + '    | ' + str((a.count(alphabet_wth_space[i])) / len(a)))
		break

print('\nWithout space\n')

l2 = len(alphabet_no_space)

for i in range(0, l2):
	d = c.count(alphabet_no_space[i])
	while i <= l2:
		if d >= 1000:
			print(str(alphabet_no_space[i]) + ' | ' + str(c.count(alphabet_no_space[i])) + ' | ' + str((c.count(alphabet_no_space[i])) / len(c)))
		elif d >= 100 and d <1000:
			print(str(alphabet_no_space[i]) + ' | ' + str(c.count(alphabet_no_space[i])) + '  | ' + str((c.count(alphabet_no_space[i])) / len(c)))
		elif d >= 10 and d < 100:
			print(str(alphabet_no_space[i]) + ' | ' + str(c.count(alphabet_no_space[i])) + '   | ' + str((c.count(alphabet_no_space[i])) / len(c)))
		else: 
			print(str(alphabet_no_space[i]) + ' | ' + str(c.count(alphabet_no_space[i])) + '    | ' + str((c.count(alphabet_no_space[i])) / len(c)))
		break

print('\n' + '=' * 120 + '\nBigrams\n\n' + '=' * 120 + '\nNon-intersectings with spaces\n')

temp_dict1 = dict()
temp_bigram1 = ''
s1 = 0

for letter in a:
	temp_bigram1 += letter
	if len(temp_bigram1) == 2:
		if temp_bigram1 in temp_dict1:
			temp_dict1[temp_bigram1] += 1
			temp_bigram1 = ''
		else:
			temp_dict1[temp_bigram1] = 1
			temp_bigram1 = ''

for key1 in temp_dict1.keys():
	s1 += temp_dict1[key1]

for key1 in temp_dict1.keys():
	if temp_dict1[key1] >= 10 and temp_dict1[key1] < 100:
		print (str(key1) + ' | ' + str(temp_dict1[key1]) + ' | ' + str((temp_dict1[key1] / s1)))
	else:
		print (str(key1) + ' | ' + str(temp_dict1[key1]) + '  | ' + str((temp_dict1[key1] / s1)))

print('\nNon-intersectings without spaces\n')

temp_dict2 = dict()
temp_bigram2 = ''
s2 = 0

for letter in c:
	temp_bigram2 += letter
	if len(temp_bigram2) == 2:
		if temp_bigram2 in temp_dict2:
			temp_dict2[temp_bigram2] += 1
			temp_bigram2 = ''
		else:
			temp_dict2[temp_bigram2] = 1
			temp_bigram2 = ''

for key2 in temp_dict2.keys():
	s2 += temp_dict2[key2]

for key2 in temp_dict2.keys():
	if temp_dict2[key2] >= 10 and temp_dict2[key2] < 100:
		print (str(key2) + ' | ' + str(temp_dict2[key2]) + ' | ' + str((temp_dict2[key2] / s2)))
	else:
		print (str(key2) + ' | ' + str(temp_dict2[key2]) + '  | ' + str((temp_dict2[key2] / s2)))

def del_char(string, indexes):  
	return ''.join((char for idx, char in enumerate(string) if idx not in indexes)) 

print('\nIntersectings with spaces\n')

temp_dict3 = dict()
temp_bigram3 = ''
s3 = 0

for letter in a:
	temp_bigram3 += letter
	if len(temp_bigram3) == 2:
		if temp_bigram3 in temp_dict3:
			temp_dict3[temp_bigram3] += 1
			temp_bigram3 = del_char(temp_bigram3, [0])
		else:
			temp_dict3[temp_bigram3] = 1
			temp_bigram3 = del_char(temp_bigram3, [0])

for key3 in temp_dict3.keys():
	s3 += temp_dict3[key3]

for key3 in temp_dict3.keys():
	if temp_dict3[key3] >= 10 and temp_dict3[key3] < 100:
		print (str(key3) + ' | ' + str(temp_dict3[key3]) + ' | ' + str((temp_dict3[key3] / s3)))
	else:
		print (str(key3) + ' | ' + str(temp_dict3[key3]) + '  | ' + str((temp_dict3[key3] / s3)))

print('\nIntersectings without spaces\n')

temp_dict4 = dict()
temp_bigram4 = ''
s4 = 0

for letter in c:
	temp_bigram4 += letter
	if len(temp_bigram4) == 2:
		if temp_bigram4 in temp_dict4:
			temp_dict4[temp_bigram4] += 1
			temp_bigram4 = del_char(temp_bigram4, [0])
		else:
			temp_dict4[temp_bigram4] = 1
			temp_bigram4 = del_char(temp_bigram4, [0])

for key4 in temp_dict4.keys():
	s4 += temp_dict4[key4]


for key4 in temp_dict4.keys():
	if temp_dict4[key4] >= 10 and temp_dict4[key4] < 100:
		print (str(key4) + ' | ' + str(temp_dict4[key4]) + ' | ' + str((temp_dict4[key4] / s4)))
	else:
		print (str(key4) + ' | ' + str(temp_dict4[key4]) + '  | ' + str((temp_dict4[key4] / s4)))

#############################

temp1 = []

for i in range(0, l):
	b = a.count(alphabet_wth_space[i])
	temp1.append(b/len(a))

#############################

temp2 = []

for i in range(0, l2):
	b = c.count(alphabet_wth_space[i])
	temp2.append(b/len(c))

#############################

temp3 = []

for key1 in temp_dict1.keys():
	b = temp_dict1[key1]
	temp3.append(b / s1)

#############################

temp4 = []

for key2 in temp_dict2.keys():
	b = temp_dict2[key2]
	temp4.append(b / s2)

#############################

temp5 = []

for key3 in temp_dict3.keys():
	b = temp_dict3[key3]
	temp5.append(b / s3)

#############################

temp6 = []

for key4 in temp_dict4.keys():
	b = temp_dict4[key4]
	temp6.append(b / s4)

#print(str(temp1) + '\n' + '\n' + str(temp2) + '\n' + '\n'  + str(temp3) + '\n' + '\n'  + str(temp4) + '\n' + '\n'  + str(temp5) + '\n' + '\n'  + str(temp6) + '\n' + '\n' )

print('\n' + '=' * 120 + '\n\nEntropy\n\n' + '=' * 120 + '\n\nEntropy for monograms with spaces')

entropy1 = 0

for p1 in temp1:
	if p1 == 0.0:
		continue
	else:
		entropy1 += (p1 * log((1/p1), 2))
print(entropy1)

redundancy1 = (1 - (entropy1 / 5))
print('\nRedundancy:\n' + str(redundancy1))

print('\nEntropy for monograms without spaces')

entropy2 = 0

for p2 in temp2:
	if p2 != 0.0:
		entropy2 += (p2 * log((1/p2), 2))
	else:
		continue
print(entropy2)

redundancy2 = (1 - (entropy2 / 5))
print('\nRedundancy:\n' + str(redundancy2))

print('\nEntropy for non-intersectings bigrams with spaces')

entropy3 = 0

for p3 in temp3:
	if p3 != 0.0:
		entropy3 += (p3 * log((1/p3), 2)) / 2
	else:
		entropy += p3
print(entropy3)

redundancy3 = (1 - (entropy3 / 5))
print('\nRedundancy:\n' + str(redundancy3))

print('\nEntropy for non-intersectings bigrams without spaces')

entropy4 = 0

for p4 in temp4:
	if p4 != 0.0:
		entropy4 += (p4 * log((1/p4), 2)) / 2
	else:
		continue
print(entropy4)

redundancy4 = (1 - (entropy4 / 5))
print('\nRedundancy:\n' + str(redundancy4))

print('\nEntropy for intersectings bigrams with spaces')

entropy5 = 0

for p5 in temp5:
	if p5 != 0.0:
		entropy5 += (p5 * log((1/p5), 2)) / 2
	else:
		continue
print(entropy5)

redundancy5 = (1 - (entropy5 / 5))
print('\nRedundancy:\n' + str(redundancy5))

print('\nEntropy for intersectings bigrams without spaces')

entropy6 = 0

for p6 in temp6:
	if p6 != 0.0:
		entropy6 += (p6 * log((1/p6), 2)) / 2
	else:
		continue
print(entropy6)

redundancy6 = (1 - (entropy6 / 5))
print('\nRedundancy:\n' + str(redundancy6))

print(input('\nEnter to exit'))
