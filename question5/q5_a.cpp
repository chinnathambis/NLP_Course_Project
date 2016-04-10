#include<bits/stdc++.h>
using namespace std;

vector<string> split(string str){
	vector<string> words;
	string token="";

	int i=2;
	while(i<str.length()){
		if(str[i]!=' ')
			token.push_back(str[i]);
		else{
			if(token.length()>0 && token[0]>='a' && token[0]<='z')
				words.push_back(token);
			token="";
		}
		i++;
	}
	if(token.length()>0 && token[0]>='a' && token[0]<='z'){
		token.erase(token.size() - 1);
		words.push_back(token);
	}


	return words;

}


int main(){
	
	FILE *file2 = fopen("trainingdata.txt","r");
	FILE *outfile = fopen("voc_9p.txt","w");
	map<string,int> vocPos;
	map<string,int> vocNeg;
	map<string,int> totalwords;
	char str1[1001];
		
	
	while(fgets(str1,1000,file2))
	{
		
		vector<string> words = split(str1);

		for(int i=0;i<words.size();i++){
			

			if(totalwords.find(words[i])==totalwords.end())
				totalwords[words[i]]=1;
			else
				totalwords[words[i]]++;


			if(str1[0]=='+')
				if(vocPos.find(words[i])==vocPos.end())
					vocPos[words[i]]=1;
				else
					vocPos[words[i]]++;
			else
				if(vocNeg.find(words[i])==vocNeg.end())
					vocNeg[words[i]]=1;
				else
					vocNeg[words[i]]++;
			
		}
	}

	map<string,int>::iterator it=totalwords.begin();
	it++;
	while(it != totalwords.end()){
		
		if((it->second)>1){
			fputs((it->first).c_str(),outfile);
			fputs(" ",outfile);

			if(vocPos.find(it->first)==vocPos.end())
				fputs("0",outfile);
			else{
				sprintf(str1, "%d", vocPos[it->first]);
				fputs(str1,outfile);
			}

			fputs(" ",outfile);
			

			if(vocNeg.find(it->first)==vocNeg.end())
				fputs("0",outfile);
			else{
				sprintf(str1, "%d", vocNeg[it->first]);
				fputs(str1,outfile);
			}

			fputs("\n",outfile);
		
		}
		it++;
	}

	fclose(file2);
	fclose(outfile);
	return 0;
}
