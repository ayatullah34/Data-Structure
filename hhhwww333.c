#include <stdio.h>
#include <stdlib.h>

struct n{
	struct n * next;
	int data;
};

int pop(struct n* root){
	if(root==NULL){
	printf("stack empty");
	return -1;
	}
	if(root->next==NULL){
		int rvalue=root->data;
		free(root);
		return rvalue;
	}
	struct n*iter=root;
	while(iter->next->next!=NULL){
		iter=iter->next;
	}
	
	struct n*temp=iter->next;
	int rvalue=temp->data;
		iter->next=NULL;
	free(temp);
  
	return rvalue;
	
}

struct n*push(struct n*root,int a){
	if(root==NULL){
		root=(struct n*)malloc(sizeof(struct n));
		root->data=a;
		root->next=NULL;
		return root;
	}
	struct n* iter=root;
	while(iter->next!=NULL)
		iter=iter->next;
	
	struct n*temp=(struct n*)malloc(sizeof(struct n*));
	temp->data=a;
	temp->next=NULL;
	iter->next=temp;
	return root;
}



int main(){
}
	struct n * s=NULL;
	s=push(s,10);
	s=push(s,20);
	printf("%d->",pop(s));
	s=push(s,30);
	printf("%d->",pop(s));
	
}
