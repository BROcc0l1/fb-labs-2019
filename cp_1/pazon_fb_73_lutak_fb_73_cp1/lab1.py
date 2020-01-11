# -*- coding: utf-8 -*-
# vim:fileencoding=utf-8
import  detectRussian
import sys, argparse, math, re
from math import log
from operator import itemgetter 
from itertools import groupby
import os
import fileinput
from collections import Counter
import string
# Read in the file
template="абвгдеёжзийклмнопрстуфхцчшщъыьэюя "
file = open("TEXT.txt", 'r',encoding='utf8', errors='ignore')
file_end = open("TEXT2.txt",'w')
line = file.readlines()

def text_change(text):
    if detectRussian.isRussian(decryptedText, wordPercentage=40, letterPercentage=100):
        break
    else:
        for l in line:
            if l not in detectRussian.UPPERLETTERS
                l=l.replace(element, ' ')
        l = ' '.join(l.split())

alphabet={}
file_1 = open("TEXT2.txt",'r')
line = file_1.readlines()
def count_letters():
    for i in line:
        for element in i.lower():
           if element in alphabet:
               alphabet[element]=alphabet[element]+1;
           else:
               alphabet[element]=1;
count_letters()
file_1.close()
print (alphabet)
alphabet_bi={}
file_2 = open("TEXT2.txt",'r')
line = file_2.read()
def count_bigramms():
	length = 0
	for i in range(1,len(line)):
		bigram = line[i-1]+line[i]
		if bigram  in alphabet_bi:
			alphabet_bi[bigram]+=1;
			length = length +1
		else:
			alphabet_bi[bigram]=1;
			length = length +1
	return length;
length = count_bigramms()
file_2.close()
print (alphabet_bi)
for value in alphabet.keys():
	alphabet[value]=alphabet[value]/len(line)
list1 = list(alphabet.items())
list1.sort(key=lambda j: j[1])
#print(list1)

for value2 in alphabet_bi.keys():
	alphabet_bi[value2]=alphabet_bi[value2]/length
list2 = list(alphabet_bi.items())
list2.sort(key=lambda i: i[1])
#print(list2)

alphabet_biwi={}
file_3 = open("TEXT2.txt",'r')
line = file_3.read()
def count_bigrammswi():
	i=0
	lengthwi=0
	while i < len(line)-1:
		bigram = line[i]+line[i+1]
		i+=2
		if bigram  in alphabet_biwi:
			alphabet_biwi[bigram]+=1;
			lengthwi = lengthwi +1
		else:
			alphabet_biwi[bigram]=1;
			lengthwi = lengthwi +1
	return lengthwi;
lengthwi = count_bigrammswi()
file_3.close()
"""print (alphabet_biwi)"""
for value3 in alphabet_biwi.keys():
	alphabet_biwi[value3]=alphabet_biwi[value3]/lengthwi
list3 = list(alphabet_biwi.items())
list3.sort(key=lambda i: i[1])
print(list3)

def ent(alp):
    for value in alp.keys():
	val = alp[value] / len(line)
	enthropia -= val * log(val,2)
    return enthropia
    
ent1 = ent(alphabet)
ent2 = ent(alphabet_bi)
ent22 = ent(alphabet_biwi)

def resid(ent):
    residuality=1-ent/log(32,2)
    return residuality

res1 = resid(ent1)
res2 = resid(ent2)
res3 = resid(ent22)
