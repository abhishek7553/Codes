#include<stdio.h>
#include<stdlib.h>
struct stack{
	int data;
	struct stack *top;
};
void push(struct stack **t,int val){
	struct stack *temp=(struct stack*)malloc(sizeof(struct stack));
	temp->data=val;
	temp->top=*t;
	*t=temp;
}
int pop(struct stack **t){
	int temp=(*t)->data;
	(*t)=(*t)->top;
	return temp;
}
void print(struct stack *t){
	while(t!=NULL){
		printf("%d-",t->data);
		t=t->top;
	}
}
void add(struct stack **t1){
	struct stack *t=*t1;
	while(t!=NULL){
		t->data+=1;
		t=t->top;
	}
}
void dequeue(struct stack **t1,struct stack **t2){
	struct stack *t=*t1;
	struct stack *s=*t2;
	while(t!=NULL){
		push(&s,pop(t1));
	}
	printf("\n\nSTACK1:");print(*t1);
	printf("\n\nSTACK2:");print(s);
	printf("\n\nDELETE ELEMENT:%d\t",pop(&s));
	printf("\n\nSTACK2:");print(s);
//	while(s!=NULL){
//		push(&t,pop(&s));
//	}
}
int main(){
	int n=5;
//	printf("ENTER NO. ELEMENTS TO BE ENTERED:");
//	scanf("%d",&n);
	struct stack *t1=NULL;
	for(int i=0;i<n;i++){
		push(&t1,i);
	}
	printf("\n\nBEFORE:");print(t1);
	struct stack *s=NULL;
	while(t1!=NULL){
		push(&s,pop(&t1));
	}
	printf("\n\nDELETE ELEMENT:%d\t",pop(&s));
	while(s!=NULL){
		push(&t1,pop(&s));
	}
	printf("\n\nAFTER:");print(t1);
	return 0;
}
