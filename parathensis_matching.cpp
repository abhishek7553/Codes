#include<stdio.h>
#include<stdlib.h>
struct stack{
	char data;
	struct stack *next;
};
void push(struct stack **p,char ch){
	struct stack *New=(struct stack*)malloc(sizeof(struct stack));
	New->data=ch;
	New->next=*p;
	*p=New;
	
}
void pop(struct stack **p)
{
	(*p)=(*p)->next;
}
int isempty(struct stack *p){
	if(p==NULL)
	   return 1;
	   return 0;
}
int isbalanced(struct stack **p,char *exp)
{
	struct stack *temp=*p;
	int i;
	for(i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='(')
		 push(&temp,exp[i]);
		 else if(exp[i]==')')
		 {
		 	if(isempty(temp))
		 	return 0;
		 	pop(&temp);
		 }
		
	}
	return isempty(temp)?0:1;	
}
int main(){
	char a[100];
	struct stack *start=NULL;
	scanf("%s",a);
	if(!isbalanced(&start,a))
	printf("blnc");
	else
	printf("nc");
	return 0;
}


