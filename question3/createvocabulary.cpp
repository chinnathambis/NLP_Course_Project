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
			if(token[0]>='a' && token[0]<='z')
				words.push_back(token);
			token="";
		}
		i++;
	}
	if(token!=""){
		token.erase(token.size() - 1);
		words.push_back(token);
	}


	return words;

}


int main(){
	
	FILE *file2 = fopen("Aftercleaneddata.txt","r");
	FILE *outfile = fopen("vocabulary.txt","w");
	map<string,int> voc;
	char str1[1001];
		
	
	while(fgets(str1,1000,file2))
	{
		
		vector<string> words = split(str1);

		for(int i=0;i<words.size();i++){
			if(voc.find(words[i])==voc.end())
				voc[words[i]]=0;
			else
				voc[words[i]]++;
		}
	}

	map<string,int>::iterator it=voc.begin();
	it++;
	while(it != voc.end()){
		if((it->second)>1){
			fputs((it->first).c_str(),outfile);
			fputs("  ",outfile);
			sprintf(str1, "%d", it->second);
			fputs(str1,outfile);
			fputs("\n",outfile);
		}
		it++;
	}

	fclose(file2);
	fclose(outfile);
	return 0;


}
