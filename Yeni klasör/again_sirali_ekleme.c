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

/*
void ekle(struct n*r,int x){
	
	while(r->next!=NULL){
		r=r->next;
	}
		r->next=(struct n*)malloc(sizeof(struct n));
		r->next->x=x;
		r->next->next=NULL;
}

*/

struct n*eklesirali(struct n*r,int x){
	if(r==NULL){//linklist boþsa...
		r=(struct n*)malloc(sizeof(struct n));
		r->next=NULL;
		r->x=x;
		return r;
	}
	
	if(r->x > x){//ilk elemandan küçük...
			struct n* temp=(struct n*)malloc(sizeof(struct n));
			temp->x=x;
			temp->next=r;
			return temp;
		}
	
	struct n *iter=r;
	while(iter->next != NULL && iter->next->x < x){
		iter=iter->next;
	}
	
	struct n* temp=(struct n*)malloc(sizeof(struct n));
	temp->next=iter->next;
	iter->next=temp;
	temp->x=x;
	
	return r;
    
	
	
}

int main(){
	
	struct n *root;
	root=NULL;

    int i=0;
	root=eklesirali(root,400);
	root=eklesirali(root,40);
	root=eklesirali(root,4);
	root=eklesirali(root,450);
	root=eklesirali(root,50);				
	print(root);
	
	
	
	return 0; 
}
