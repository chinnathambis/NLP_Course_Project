#include <string>
#include <vector>
#include <fstream>
#include <iostream>
float totalpve=1,totalnve=1;
using namespace std;
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
  ifstream fin("vocabulary.txt");
  ifstream fn("Aftercleaneddata.txt");
  while (fin>>str>>pc>>nc) 
  {          
        
    	voc.push_back(str);
	positiveCounts.push_back(pc);
	negativeCounts.push_back(nc);	
  }
  fin.close();
v=voc.size();
while(getline(fn,str2))
{

	int count=countWords(str2);
	if(str2[0]=='+')
	{
		p+=count;
		
	}
	else if(str2[0]=='-')
	{
		n+=count;
	}

}	
   fn.close();
cout<<"positive words = "<<p<<endl;
cout<<"negative words = "<<n<<endl;
cout<<"\nEnter the word for finding probability\n" ;
string word;
cin>>word;
int flag=0;
for(int i=0;i<voc.size();i++)
{
	if(voc[i].compare(word)==0)
	{
		float positiveProb=((positiveCounts[i]+1)*1.0)/(p+v);
		float negativeProb=((negativeCounts[i]+1)*1.0)/(n+v);
		cout<<"P("<<word<<"/+) : "<<positiveProb<<endl;
		cout<<"P("<<word<<"/-) : "<<negativeProb<<endl;
		flag=1;
	}
}
	if(flag==0)
	{
		float positiveProb=(1*1.0)/(p+v);
		float negativeProb=(1*1.0)/(n+v);
		cout<<"P(word/+) : "<< positiveProb <<endl;
		cout<<"P(word/-) : "<< negativeProb <<endl;
	}
  return 0;
}
