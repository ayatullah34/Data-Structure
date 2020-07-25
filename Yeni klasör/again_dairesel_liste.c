#include<stdio.h>
#include<stdlib.h>

struct n{
	
	int x;
	struct n *next;
};

void print(struct n*r){
	struct n*iter=r;
	printf("%d ",iter->x);
	iter=iter->next;
	while(iter!=r){
		printf("%d ",iter->x);
		iter=iter->next;
	}
	printf("\n");
}


void ekle(struct n*r,int x){
	struct n*iter=r;
	while(iter->next != r){
		iter=iter->next;
	}
		iter->next=(struct n*)malloc(sizeof(struct n));
		iter->next->x=x;
		iter->next->next=r;
}

///////////////////////-------SIRALI EKLEME----------------

struct n*eklesirali(struct n*r,int x){
	
	if(r==NULL){//linklist boþsa...
		r=(struct n*)malloc(sizeof(struct n));
		r->next=r;
		r->x=x;
		return r;
	}
	
	if(r->x > x){//ilk elemandan küçük...
			struct n* temp=(struct n*)malloc(sizeof(struct n));
			temp->x=x;
			temp->next=r;
			
			struct n*iter=r;
			while(iter->next != r){
				iter=iter->next;
			}
			iter->next=temp;
			return temp;
		}
	
	struct n *iter=r;
	while(iter->next != r && iter->next->x < x){
		iter=iter->next;
	}
	
	struct n* temp=(struct n*)malloc(sizeof(struct n));
	temp->next=iter->next;
	iter->next=temp;
	temp->x=x;
	
	return r;
    
}


///////////////////////////--------------SÝLME----------------

struct n* sil(struct n*r,int x){
	struct n*temp;
	struct n*iter=r;
	
	if(r->x==x){
		while(iter->next != r){
			iter=iter->next;
		}
		iter->next=iter->next->next;
		free(r);
		
		return iter->next;
	}
	
	while(iter->next != r && iter->next->x != x){
		iter=iter->next;
	}
	
	if(iter->next == r){
		printf("sayi bulunamadi");
		return r;
	}
	
	temp=iter->next;
	iter->next=iter->next->next;
	free(temp);
	
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
