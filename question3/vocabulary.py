#! usr/bin/env python 
import re
import sys

#file reading data.txt and vocabulary.txt

file_data_obj = open('data.txt','r')
file_vocabulary_obj = open('vocabulary.txt','w')

l = file_data_obj.readline().split()

vocabulary_words = []
while l:
    review = l.pop()
    vocabulary_words.extend(l)
    l = file_data_obj.readline().split()
    
v = []
for w in vocabulary_words:
    if w.isalpha():
        if w!='+' and w!='-':
            if v.count(w) == 0:
                if vocabulary_words.count(w)>1:
                    v.append(w)
                    

#sorting vocabulary list
v.sort()

for w in v:
    file_vocabulary_obj.write(w+'\n')

print file_vocabulary_obj

file_data_obj.close()
file_vocabulary_obj.close()
