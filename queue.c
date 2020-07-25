#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node * next;
	int data;
};


struct node *root=NULL;
struct node*son=NULL;
void enqueue(int x){
	if(root==NULL){
		root=(struct node*)malloc(sizeof(struct node));
		root->data=x;
		root->next=NULL;
		son=root;
	}
	else{
		son->next=(struct node*)malloc(sizeof(struct node));
		son->next->data=x;
		son=son->next;
		son->next=NULL;
		
	}
	
}

int dequeue(){
	if(root==NULL){
		printf("linked list empty");
		return -1;
	}
	
	int rvalue=root->data;
	struct node*temp=root;
	root=root->next;
	free(temp);
	return rvalue;
}



int main(){
	
	enqueue(10);
	enqueue(20);
	enqueue(30);
	printf("%d->",dequeue());
	//printf("%d->",dequeue());
	//printf("%d->",dequeue());

	
	return 0;
} 
