from itertools import islice
from itertools import izip
import collections
import re


def vocabulary(filename):
    
	f1 = open(filename, "r")
	f1.seek(0,0)
	file_data = f1.read() 
	words = file_data.split()
	count = data_file.Counter()
	
	for word in words:
		count[word] = count[word] + 1


	v = open("vocabulary.txt","w")
	for word in count:
		if count[word] >= 3:
			v.write(word+"\n")	

	v.close()
	f1.close()



def bigram(filename):
    
	inFile = open(filename,"r")
	dataset_content = inFile.read()
	words = dataset_content.split()

	create_bigrams = collections.Counter(izip(words, islice(words,1,None)))

	inFile.close()

	
	inFile = open("vocabulary.txt","a+")
	for word in create_bigrams:
		if create_bigrams[word] >= 3:
			inFile.write(" ".join(word))
			inFile.write("\n")
			
	v = open("new_vocabulary.txt","w")
	
	inFile.seek(0,0)
	for line in inFile:
            
		if(not line.startswith('+') and not line.startswith('-') and not line[-2:-1] == '+' and not line[-2:-1] == '-'):
#               if(not line[2:1] == '+' and not line[2:1] == '-'and not line.startswith('+') and not line.startswith('-')):
			v.write(line)
	inFile.close()
	v.close()

	#print "successful...!"


bigram("aftercleaneddata.txt")
