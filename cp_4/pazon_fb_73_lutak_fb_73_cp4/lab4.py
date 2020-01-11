from queue import Queue
from textwrap import wrap
import collections
p1 = [1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0]
p2 = [1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0]

file1 = open("outputlab4.txt", 'r+')
file2 = open("ngramms.txt",'r+')
line1 = file1.readlines()
line2= file2.readlines()
lst = []
template = "01"

def gen0(arr):
    posl = [0]*(len(arr)-1)
    posl.append(1)
    #print(posl)
    return posl
    
def movearray(array, res):
    #w = array[0]
    for i in range(1):
        array.append(array.pop(0))
    array[len(array)-1] = res
    return array
a1 = gen0(p1)
a2 = gen0(p2)
def count(array, polinom):
    sum = 0
    for i in range(0, len(array)):
        sum+=array[i]*polinom[i]
    movearray(array, sum%2)
    
t1=1
count(a1, p1)
while a1 != gen0(p1):
    file1.write(str(a1[0]))
    count(a1, p1)
    t1+=1
    #for i in range(0,len(a1)):
        
    

print(t1)

t2=1
count(a2, p2)
while a2 != gen0(p2):
    file2.write(str(a2[0]))
    count(a2, p2)
    t2+=1
    #for i in range(0,len(a1)):
        
    

print(t2)

'''def cout_ngram(fileq, filew, ngram):
    #wrap(file1, n)
    filew.write(wrap(fileq, ngram))
    
print('input n')
nq = int(input())
cout_ngram(file1, file2, nq)
'''
bigram = {}
bigram11 = {}
length = 0
def gramm(line,grm, bigram,n):
    
    n2=0
    gramm3 = line[i-1]+line[i]+line[i+1]
    n3=1
    gramm4 = line[i-1]+line[i]+line[i+1]+line[i+2]
    n4=2
    gramm5 = line[i-1]+line[i]+line[i+1]+line[i+2]+line[i+3]
    n5=3
    for i in range(1,len(line)):
        length = 0
		gramm2 = line[i-1]+line[i]
		if gramm2 in bigram:
			bigram[gramm2]+=1;
			length = length +1
		else:
			bigram[gramm2]=1;
			length = length +1
    for i in range(1,len(line)-1):
        length = 0
		gramm3 = line[i-1]+line[i]+line[i+1]
		if gramm3 in bigram:
			bigram[gramm3]+=1;
			length = length +1
		else:
			bigram[gramm3]=1;
			length = length +1
    for i in range(1,len(line)-2):
        length = 0
		gramm4 = line[i-1]+line[i]+line[i+1]+line[i+2]
		if gramm4 in bigram:
			bigram[gramm4]+=1;
			length = length +1
		else:
			bigram[gramm4]=1;
			length = length +1
    for i in range(1,len(line)-3):
        length = 0
		gramm5 = line[i-1]+line[i]+line[i+1]+line[i+2]+line[i+3]
		if gramm5 in bigram:
			bigram[gramm5]+=1;
			length = length +1
		else:
			bigram[gramm5]=1;
			length = length +1
    return bigram
bigram = gramma(line1,5, bigram)
bigram11 = gramma(line2,5, bigram11)
print(bigram)
print(bigram11)
new_d={}
for k in sorted(bigram, key=len, reverse=False):
    new_d[k] = bigram[k]

new_d1={}
for i in sorted(bigram11, key=len, reverse=False):
    new_d1[i] = bigram11[i]
    
def autocorellation(T, array, polinom):
    sum = [0]*10
    j = 0
    while j < T:
        count(array, polinom)
        for i in range(0,10):
            sum[i] = sum[i] + (array[0] + array[i+1])%2
        j+=1
    return sum

print(autocorellation(t1, a1, p1 ))
print(autocorellation(t2, a2, p2 ))
file = file1.read()
line = file2.readlines()


    

file1.close()
file2.close()