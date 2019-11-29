#include<iostream>
using namespace std;
template <class T>
void fun(T x,T y){
cout<<"template :";	cout<<x<<y;
}
void fun(int x,int y){
cout<<"non-template :";	cout<<x<<y;
}
int main(){
	fun(1,3);cout<<endl;
	fun(2,'a');cout<<endl;
	fun('q','w');cout<<endl;
	return 0;
}

