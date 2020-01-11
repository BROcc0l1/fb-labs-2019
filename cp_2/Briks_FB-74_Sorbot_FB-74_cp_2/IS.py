alphabet_no_space = ['а','б','в','г','д','е','ё','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ь','ъ','ы','э','ю','я']

A = input('IS for PlainText (P) or CypherText (C)?\n\n')
print('')

input1 = open('D:/FIELS/CRYPT/LAB2/Crypted_text.txt', 'r', encoding = 'utf-8')
input2 = open('D:/FIELS/CRYPT/LAB2/open_text.txt', 'r', encoding = 'utf-8')
c = input1.read()
e = input2.read()

l2 = len(alphabet_no_space)
chis = 0
znam = (len(c) * (len(c) - 1))
znam2 = (len(e) * (len(e) - 1))
IS = 0

if A == 'C' or A == 'c':
	for i in range(0, l2):
		d = c.count(alphabet_no_space[i])
		while i <= l2:
			chis = (c.count(alphabet_no_space[i]) * (c.count(alphabet_no_space[i]) - 1))
			MS = chis / znam
			IS += MS
			if d >= 1000:
				print(str(alphabet_no_space[i]) + ' | ' + str(c.count(alphabet_no_space[i])) + ' | ' + str((c.count(alphabet_no_space[i]) / len(c))))
			elif d >= 100 and d <1000:
				print(str(alphabet_no_space[i]) + ' | ' + str(c.count(alphabet_no_space[i])) + '  | ' + str((c.count(alphabet_no_space[i]) / len(c))))
			elif d >= 10 and d < 100:
				print(str(alphabet_no_space[i]) + ' | ' + str(c.count(alphabet_no_space[i])) + '   | ' + str((c.count(alphabet_no_space[i]) / len(c))))
			else: 
				print(str(alphabet_no_space[i]) + ' | ' + str(c.count(alphabet_no_space[i])) + '    | ' + str((c.count(alphabet_no_space[i]) / len(c))))
			break
	
	print('\nIS: ' + str(IS))

elif A == 'P' or A == 'p':
	for i in range(0, l2):
		d = e.count(alphabet_no_space[i])
		while i <= l2:
			chis = (e.count(alphabet_no_space[i]) * (e.count(alphabet_no_space[i]) - 1))
			MS = chis / znam2
			IS += MS
			if d >= 1000:
				print(str(alphabet_no_space[i]) + ' | ' + str(e.count(alphabet_no_space[i])) + ' | ' + str((e.count(alphabet_no_space[i]) / len(c))))
			elif d >= 100 and d <1000:
				print(str(alphabet_no_space[i]) + ' | ' + str(e.count(alphabet_no_space[i])) + '  | ' + str((e.count(alphabet_no_space[i]) / len(c))))
			elif d >= 10 and d < 100:
				print(str(alphabet_no_space[i]) + ' | ' + str(e.count(alphabet_no_space[i])) + '   | ' + str((e.count(alphabet_no_space[i]) / len(c))))
			else: 
				print(str(alphabet_no_space[i]) + ' | ' + str(e.count(alphabet_no_space[i])) + '    | ' + str((e.count(alphabet_no_space[i]) / len(c))))
			break

	print('\nIS: ' + str(IS))


else:
	print('Wrong value')

print(input('\nEnter to extit'))