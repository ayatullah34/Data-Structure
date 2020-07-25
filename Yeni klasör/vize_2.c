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



struct n* sil(struct n*r,int x){
	struct n*temp;
	struct n*iter=r;
	if(r->x == x){
		temp=r;
		r=r->next;
		free(temp);
		return r;
	}
	
	while(iter->next != NULL && iter->next->x != x){
		iter=iter->next;
	}
	
	if(iter->next==NULL){
		printf("number doesn't exist ");
		return r;
	}
	
	temp=iter->next;
	iter->next=iter->next->next;
	free(temp);
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
	 
	root=sil(root,50);
	print(root);
    
	root=sil(root,999);
	print(root);
    
	root=sil(root,4);
	print(root);
    
	root=sil(root,450);
	print(root);
	 

	
	
	
	return 0;
}
