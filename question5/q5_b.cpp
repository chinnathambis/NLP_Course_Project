#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include<iomanip>
using namespace std;
double totalpve=1,totalnve=1;
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
int countWords(string str)
{
	int count=0;
	int flag=0;
	for(int i=2;i<str.size();i++)
	{	
		if(flag==1&&(str[i]==' '||str[i]=='\n'))
		{
			count++;
			flag=0;
		}
		else if(isalpha(str[i]))
		{
			flag=1;
		}		
	}
	if(flag==1)
		count++;
	return count;
}
int main()
{
  int v,t,p=0,n=0,pc,nc;

  vector <string> voc;
  
  vector <string> voct;
  vector<int> positiveCounts;
  vector<int> negativeCounts;
  string str;
  string str1;
  string str2;
  ifstream fin("voc_9p.txt");
  ifstream fn("testdata.txt");
  while (fin>>str>>pc>>nc) 
  {          
        
    	voc.push_back(str);
	positiveCounts.push_back(pc);
	negativeCounts.push_back(nc);
	p+=pc;
	n+=nc;	
  }
  fin.close();
int vocsize=voc.size();
int correct=0,wrong=0;

while(getline(fn,str2))
{

	totalpve=1;
	totalnve=1;
	
	vector<string> word=split(str2);
	for(int j=0;j<word.size();j++){
		bool flag=0;

		for(int i=0;i<voc.size();i++)
		{
			if(voc[i].compare(word[j])==0)
			{
				double positiveProb=((positiveCounts[i]+1)*1.0)/(p+vocsize);
				double negativeProb=((negativeCounts[i]+1)*1.0)/(n+vocsize);
				totalpve*=positiveProb;
				totalnve*=negativeProb;

				flag=1;

				break;		
			}
		}
		if(flag==0)
		{
			double positiveProb=(1*1.0)/(p+vocsize);
			double negativeProb=(1*1.0)/(n+vocsize);
			totalpve*=positiveProb;
			totalnve*=negativeProb;

			
		}
		
		
	}
	
	
		
	if(totalpve>=totalnve && str2[0]=='+')
		correct++;
	else if(totalpve<totalnve && str2[0]=='-')
		correct++;
	else
		wrong++;
	

}	  
cout<<"Correct Prediction: "<<correct<<endl;
cout<<"Wrong Prediction: "<<wrong<<endl;
cout<<"Accuracy: "<<(double)correct/(correct+wrong)*100<<"%"<<endl;
return 0;
}
