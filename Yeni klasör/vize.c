#include<stdio.h>
#include<stdlib.h>

struct n{
	int x;
	struct n* next;
};

void print(struct n* r){
	while(r!=NULL){
		printf("%d ",r->x);
		r=r->next;
	}
	printf("\n");

}

void ekle(struct n* r,int x){
	
	while(r->next!=NULL){
		r=r->next;
	}
	
	r->next=(struct n*)malloc(sizeof(struct n));
	r->next->x=x;
	r->next->next=NULL;
	
	
}


struct n* eklesirali(struct n*r,int x){
	if(r==NULL){
		r=(struct n*)malloc(sizeof(struct n));
		r->x=x;
		r->next=NULL;

		return r;
	}
	if(r->x > x){
		struct n*temp=(struct n*)malloc(sizeof(struct n));
		temp->x=x;
		temp->next=r;

		return temp;
	}
	
	struct n* iter=r;
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
	
	struct n* root;
	struct n* iter;
	int i;
	root=(struct n*)malloc(sizeof(struct n));
	root=NULL;
	 
	 root=eklesirali(root,400);
	 root=eklesirali(root,40);
	 root=eklesirali(root,4);
	 root=eklesirali(root,450);
	 root=eklesirali(root,50);
	 
	 print(root);
	 
/*
	root->x=500;
	root->next=NULL;
    
	
	for(i=0;i<5;i++){
		ekle(root,i*10);
	}
	print(root);
	

//-----//-----//-------ARAYA EKLEME------------
	iter=root;
	for(i=0;i<3;i++){
		iter=iter->next;
	}
	struct n*temp=(struct n*)malloc(sizeof(struct n));
	
	temp->next=iter->next;
	iter->next=temp;
	temp->x=100;
	print(root);
	
//--------//----------//------//--------//-------//----//
	
*/	

	
	
	
	return 0;
}
