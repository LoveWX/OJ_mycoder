#include<iostream>
#include<string>
#include<map>
using namespace std;

map <string, string> word1;
map <string, string> word2;

map<string,string>::const_iterator cit;

int main()
{
	int i,n;
	char str[120];
	while(gets(str))
	{
		if(strcmp(str,"@END@")==0)
			break;
		for(i=1;str[i]!=']';i++);
		str[i]='\0';
		string s1(str+1);
		string s2(str+i+2);
		word1[s1]=s2;
		word2[s2]=s1;
	}
	scanf("%d",&n);
	getchar();
	while(n-->0)
	{
		gets(str);
		if(str[0]=='[')
		{
			str[strlen(str)-1]='\0';
			string s1(str+1);
			cit=word1.find(s1);
			if(cit==word1.end())
			{
				cout<<"what?"<<endl;
			}
			else
			{
				cout<<word1[s1]<<endl;
			}
		}
		else
		{
			string s2(str);
			cit=word2.find(s2);
			if(cit==word2.end())
			{
				cout<<"what?"<<endl;
			}
			else
			{
				cout<<word2[s2]<<endl;
			}
		}
	}
	return 0;
}
