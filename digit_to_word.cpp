#include<iostream>
using namespace std;
void d2w(int x){
	int count=1;
	int n=x;
	while(n){
		count*=10;
		n=n/10;
	}
	float num=x;
//	cout<<count;
//	cout<<num<<endl;
	num=num/(count);
	cout<<"IN WORDS:";
	while(count>1){
		num=num*10;
		int x=num;
		num=num-x;
		switch(x){
			case 0:cout<<"ZERO ";break;
			case 1:cout<<"ONE ";break;
			case 2:cout<<"TWO ";break;
			case 3:cout<<"THREE ";break;
			case 4:cout<<"FOUR ";break;
			case 5:cout<<"FIVE ";break;
			case 6:cout<<"SIX ";break;
			case 7:cout<<"SEVEN ";break;
			case 8:cout<<"EIGHT ";break;
			case 9:cout<<"NINE ";break;
			}
		count=count/10;
	}	
}
int main(){
	cout<<"ENTER ANY NUMBER:";
	int x;
	cin>>x;
	d2w(x);
	return 0;
}
