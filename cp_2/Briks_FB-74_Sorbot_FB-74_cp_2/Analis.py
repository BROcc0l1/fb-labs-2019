alphabet_no_space = ['а','б','в','г','д','е','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ъ','ы','ь','э','ю','я']
input2 = open('D:/FIELS/CRYPT/LAB2/VAR_ENC.txt', 'r', encoding = 'utf-8')
c = input2.read()
c.replace(' ','')

import re
c
reg = re.compile('[^а-я]')
c = (reg.sub('', c))

j = int(input('Enter the lenth of the key: '))
print('')

counter = j
temptext = ""
for i in c:
	if (counter == j):
		temptext = temptext + i 
		counter = 0
	counter += 1

import re

reg = re.compile('[^а-я]')
temptext = reg.sub('', temptext)

l2 = len(alphabet_no_space)
chis = 0
znam = (len(temptext) * (len(temptext) - 1))
IS = 0

for z in range(0, l2):
	while z <= l2:
		chis = (temptext.count(alphabet_no_space[z]) * (temptext.count(alphabet_no_space[z]) - 1))
		MS = chis / znam
		IS += MS
		if temptext.count(alphabet_no_space[z]) >= 100:
			print(str(alphabet_no_space[z]) + ' | ' + str(temptext.count(alphabet_no_space[z])) + ' | ' + str((temptext.count(alphabet_no_space[z]) / len(temptext))))
		elif temptext.count(alphabet_no_space[z]) < 100 and temptext.count(alphabet_no_space[z]) >= 10:
			print(str(alphabet_no_space[z]) + ' | ' + str(temptext.count(alphabet_no_space[z])) + '  | ' + str((temptext.count(alphabet_no_space[z]) / len(temptext))))
		else:
			print(str(alphabet_no_space[z]) + ' | ' + str(temptext.count(alphabet_no_space[z])) + '   | ' + str((temptext.count(alphabet_no_space[z]) / len(temptext))))
		break

print('\nIS: ' + str(IS))


blocks = []
i = 0

for i in range(0, j):
	blocks.append('')


for w in c:
	blocks[i] = blocks[i] + w
	i += 1
	if i == j:
		i = 0

for i in range(0, j):
	print('\nBlock number ' + str(i) + ':')
	print('')
	print(blocks[i])
	print('')
	for z in range(0, l2):
		blocks[i].count(alphabet_no_space[z]) / len(blocks[i])
		if blocks[i].count(alphabet_no_space[z]) >= 100:
			print(str(alphabet_no_space[z]) + ' | ' + str(blocks[i].count(alphabet_no_space[z])) + ' | ' + str((blocks[i].count(alphabet_no_space[z]) / len(blocks[i]))))
		elif blocks[i].count(alphabet_no_space[z]) < 100 and blocks[i].count(alphabet_no_space[z]) >= 10:
			print(str(alphabet_no_space[z]) + ' | ' + str(blocks[i].count(alphabet_no_space[z])) + '  | ' + str((blocks[i].count(alphabet_no_space[z]) / len(blocks[i]))))
		else:
			print(str(alphabet_no_space[z]) + ' | ' + str(blocks[i].count(alphabet_no_space[z])) + '   | ' + str((blocks[i].count(alphabet_no_space[z]) / len(blocks[i]))))

print('')
print(input('Enter to exit'))