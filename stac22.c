#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node * next;
	int data;
};

struct node* top=NULL;
void push(int veri){
	struct node*eklenecek=(struct node*)malloc(sizeof(struct node));
	eklenecek->data=veri;
	eklenecek->next=NULL;
	if(top!=NULL){
		eklenecek->next=top;
	}
	 top=eklenecek;
}

void pop(){
	if(top->data==NULL){
		printf("stack empty");
	}
	else{
		struct node*temp;
		temp=top;
		top=top->next;
		free(temp);
	}
}

int peek(){
	return top->data;
}

void print(){
	struct node*q;
	q=top;
	printf("\n");
	while(q!=NULL){
		printf("%d->",q->data);
		q=q->next;
	}
	printf("NULL");
}

int main(){
int secim;
while(1==1){
	printf("\n1- push");
	printf("\n2- pop");
	printf("\n3- peek\n");
	printf("choose");
	scanf("%d",&secim);

	switch(secim){
		case 1:
			printf("sayi sec");
			scanf("%d",&secim);
			push(secim);
			print();
			break;
		case 2:
			pop();
			print();
			break;
		case 3:
		printf("top::%d",peek());	
		break;
}
}
	
	return 0;
} 
