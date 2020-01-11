import collections
import frequencyAnalisys
template="абвгдежзийклмнопрстуфхцчшщъыьэюя"
file = open("lab2text.txt", "r+")
file_end = open("lab2text2.txt",'r+', encoding = 'utf-8')
dict = open("alphabet.txt", 'r+', encoding='utf8', errors='ignore')
line = file.readlines()
dictionary = dict.read()

key = input()
letter = {}
def index(text):
    letters = 0
    for i in text:
        for j in dictionary:
            if i == j:
                if i in letter:
                    letter[i]+=1
                    letters+=1
                else:
                    letter[i]=1
                    letters = 1
    t = wrap(letter,1)
    while q < len(letter):
        amount = count(t[q])
        w = amount*(amount-1)    
        ind = (1/len(text)*(len(text)-1)*w
    return ind

def encrypt(string, key1): 
    cipher_text = [] 
    for i in range(len(string)): 
        x = (ord(string[i]) + 
             ord(key1[i])) % 32
        x += ord('А') 
        cipher_text.append(chr(x)) 
    return("" . join(cipher_text))
    
ewq = encrypt(list(line),key)
print(ewq)

def text_split(text,length):
    currentletter = 0
    total = ''
    for currentletter in range(0,len(text)-1):
        total = total + text[currentletter]
        currentletter = currentletter + length
    return total

indexes = {}
s = 0 
for s in range(0,30):
    s+=1
    indexx=index(text_split(file,s))
    print(indexx)
    indexes[s]=int(indexx)

maximum_index=max(indexes.values)    
key_len=indexes.get(maximum_index)

caesar=''
let=0
possible_key=''
for let in range(0,key_len-1):
    caesar=text_split(line,key_len)
    frequent=frequencyAnalisys.theMostFrequent
    kkeeyy=(ord(frequent)-ord('о'))%32
    possible_key.append(kkeeyy)

print(possible_key)

def decryption(text,keyy):
    orig_text = [] 
    for i in range(len(text)): 
        x = (ord(text[i]) - 
             ord(keyy[i]) + 32) % 32
        x += ord('а') 
        orig_text.append(chr(x)) 
    return("" . join(orig_text)) 

www=decryption(line,possible_key)
print(www)