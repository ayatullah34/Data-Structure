#include<stdio.h>
#include<stdlib.h>

struct n{
	int data;
	struct n*sol;
	struct n*sag;
};

struct n* ekle(struct n*agac,int x){
	if(agac==NULL){
		struct n*root=(struct n*)malloc(sizeof(struct n));
		root->sol=NULL;
		root->sag=NULL;
		root->data=x;
		
		return root;
	}
	
	struct n*iter=agac;
	if(iter->data < x){
		agac->sag=ekle(agac->sag,x);
		return agac;
	}
	else{
		agac->sol=ekle(agac->sol,x);
		return agac;	
	}
	
}
	
void traverse_dolas(struct n*agac){
	if(agac==NULL){
		return;
	}
	
	traverse_dolas(agac->sol);
	printf("%d ",agac->data);
	traverse_dolas(agac->sag);
	
}
	
int bul(struct n*agac,int aranan){
	if(agac == NULL){
		return -1;
	}
	
	if(agac->data == aranan){
		return 1;
	}
	
	if(bul(agac->sag,aranan) == 1)
		return 1;
	
	if(bul(agac->sol,aranan) == 1)
		return 1;
	
	return -1; 
}	
	
int max(struct n*agac){
	while(agac->sag != NULL){
		agac=agac->sag;
	}
	return agac->data;
}

int min(struct n*agac){
	while(agac->sol != NULL){
		agac=agac->sol;
	}
	return agac->data;
}

struct n* sil(struct n*agac,int x){
	if(agac == NULL){
		return NULL;
	}
	
	if(agac->data == x){
		if(agac->sol == NULL && agac->sag == NULL){
			return NULL;
		}
		
		if(agac->sag != NULL){
			agac->data=min(agac->sag);
			agac->sag=sil(agac->sag,min(agac->sag));
			return agac;
		}	
		
		agac->data=max(agac->sol);
		agac->sol=sil(agac->sol,max(agac->sol));
		return agac;
	}
	
	if(agac->data < x){
		agac->sag=sil(agac->sag,x);
		return agac;
	}
	agac->sol=sil(agac->sol,x);
	return agac;
}


int main(){
	struct n*agac=NULL;
	agac=ekle(agac,26);
	agac=ekle(agac,12);
	agac=ekle(agac,200);
	agac=ekle(agac,190);
	agac=ekle(agac,213);
	agac=ekle(agac,56);
	agac=ekle(agac,24);
	agac=ekle(agac,18);
	agac=ekle(agac,27);
	agac=ekle(agac,28);
	
	traverse_dolas(agac);
	printf("\n");
	
	printf("arama sonucu: %d\n",bul(agac,24));
	printf("arama sonucu: %d\n",bul(agac,100));
	
	printf("max=%d min=%d",max(agac),min(agac));
	printf("\n");
	
	agac=sil(agac,190);
	agac=sil(agac,56);
	agac=sil(agac,12);
	traverse_dolas(agac);
	
	return 0;
}
