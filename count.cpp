#include<iostream>
using namespace std;

class base{
	public:
	
		virtual void show(){
	cout<<"in base";
		}
};
class derived:public base{	
	int x;
	public:
		void change(derived *t){
			this = t;
		}
		void add(int x)
		{
			this->x=x;
		}
		void show(){
			cout<<"in derived";
		}
		void print(){
			cout<<x;
		}
};
int main(){
	base *bp= new derived;
	bp->show();
	cout<<endl;
	base &br=*bp;
	br.show();
	cout<<endl;
	cout<<sizeof(bp);
	return 0;
	derived l;
	l.add(10);
	l.change(2);
	cout<<l.print();
}
