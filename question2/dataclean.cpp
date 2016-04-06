#include<bits/stdc++.h>
using namespace std;

vector<string> split(string str){
	vector<string> words;
	string token="";

	int i=0;
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
	

	FILE *file1 = fopen("stopwords.txt","r");
	FILE *file2 = fopen("dataset.txt","r");
	FILE *outfile = fopen("Aftercleaneddata.txt","w");
	map<string,int> stopwords;
	char str1[1001];
	int i=1;
	while(fgets(str1,1000,file1)!=NULL)
	{
		stopwords[str1]=i;
		i++;
	}
	
	char te[3];
	while(fgets(str1,1000,file2))
	{
		string str(str1);
		te[0]=str[0];
		te[1]=' ';
		te[2]='\0';
		fputs(te,outfile);
		string temp;
		string temp2;
		
		int i=2;
		while(i<str.length()){
			if(str[i]>='a' && str[i]<='z')
				temp.push_back(str[i]);
			else if(str[i]>='A' && str[i]<='Z')
				temp.push_back(str[i]+32);
			else if(str[i]==' ' && str[i-1]!=' ')
				temp.push_back(str[i]);
			i++;
		}
		
		
		vector<string> words = split(temp);
		
		for(int i=0;i<words.size();i++){
			if(stopwords.find(words[i])==stopwords.end()){
				fputs(words[i].c_str(),outfile);
				if(i!=words.size()-1)
					fputs(" ",outfile);
			}
		}
		fputs("\n",outfile);
	}
	fclose(file1);
	fclose(file2);
	fclose(outfile);
	return 0;


}
