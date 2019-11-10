#include<iostream>
#include<string.h>
using namespace std;
class String{
	char *s;
	public:
		String(int n){
			s=new char[n];
		}
		String(int n,char *d){
			s=new char[n];
			strcpy(s,d);
		}

		void print()
	{
		cout<<s;
	}
	String operator+(String l){
	/*	int x=strlen(l.s)+strlen(s);
		String j(x-1);
		int i,k;
		for(i=0;s[i]!='\0';i++)
		j.s[i]=s[i];
		for(k=0;i<=x&&l.s!='\0';i++,k++)
	
	*/	strcat(l.s,s);
	//	j.s[i]=l.s[k];
		return l;
	}
		
};
int main(){
	char q[5]={'a','b','c','v','f'};
	char p[5]={'x','q','w','e','r'};
	String a(5,q),b(5,p);
	b.print();cout<<endl;
	a.print();cout<<endl;
	String c=a+b;
	c.print();
	return 0;
}
