#include<stdio.h>
#include<stdlib.h>

struct n{
	int x;
	struct n*next;
};

void bastir(struct n*r){
	while(r!=NULL){
		printf("%d ",r->x);
		r=r->next;
	}
}

void ekle(struct n*r,int x){
	while(r->next != NULL){
	   	r=r->next;
	}
	r->next=(struct n*)malloc(sizeof(struct n*));
	r->next->x=x;
	r->next->next=NULL;
}

struct n*sirali_ekle(struct n*r,int x){
	
	if(r==NULL){
		r=(struct n*)malloc(sizeof(struct n*));
		r->next=NULL;
		r->x=x;
		return r;
	}
	
	if(r->x > x){
		struct n*temp=(struct n*)malloc(sizeof(struct n*));
		temp->x=x;
		temp->next=r;
		return temp;
	}
	
	struct n*iter=r;
	while(iter->next != NULL && iter->next->x < x){
		iter=iter->next;
	}
	
	struct n*temp=(struct n*)malloc(sizeof(struct n*));
	temp->next=iter->next;
	iter->next=temp;
	temp->x=x;
	return r;
	
}

int main(){
	struct n*root;
	root=NULL;
	//root=(struct n*)malloc(sizeof(struct n*));
	//root->next=NULL;
	//root->x=500;
	root=sirali_ekle(root,400);
	root=sirali_ekle(root,40);
	root=sirali_ekle(root,4);
	root=sirali_ekle(root,450);
	root=sirali_ekle(root,50);
	bastir(root);	
	
	return 0;
}
