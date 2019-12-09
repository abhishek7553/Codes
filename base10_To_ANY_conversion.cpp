#include<stdio.h>
#include<stdlib.h>
#define x 25.26f
#define n 2
int count=3;
void rec(int num){
	if(num==0)
		return ;
	else{
		rec(num/n);	
		if(num%n<9)	
		printf("%d",num%n);
		else{
			printf("%c",(char)(55+num%n));
		}
	}
}

int main(){
	int num=x;
	rec(num);
	printf(".");
	float dec=(x-num);
	while(count!=0&&dec!=0.0){
		if((int)(dec*n)<9)
		printf("%d",(int)(dec*n));
		else{
			printf("%c",(char)(55+(int)(dec*n)));
		}
		dec=((float)(dec*n)-(int)(dec*n));
		count--;
	}
	return 0;
}
