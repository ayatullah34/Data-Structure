#include<stdio.h>
#include<stdlib.h>

struct n{
	
	int x;
	struct n *next;
};

void print(struct n*r){
	while(r!=NULL){
		printf("%d ",r->x);
		r=r->next;
	}
}

void ekle(struct n*r,int x){
	
	while(r->next!=NULL){
		r=r->next;
	}
		r->next=(struct n*)malloc(sizeof(struct n));
		r->next->x=x;
		r->next->next=NULL;
}


int main(){
	
	struct n *root;
	root=(struct n*)malloc(sizeof(struct n));
	root->next=NULL;
	root->x=500;
	struct n*iter=root;
    int i=0;
	
	for(i=0;i<5;i++){
		ekle(root,i*10);
	}
	print(root);
	
	/////-----------ARAYA EKLEME---------
	iter=root;
	for(i=0;i<3;i++){
		iter=iter->next;
	}
	struct n* temp=(struct n*)malloc(sizeof(struct n));
	temp->next=iter->next;
	iter->next=temp;
	temp->x=100;
	print(root);
	//////////////////////////////////////
	return 0; 
}
