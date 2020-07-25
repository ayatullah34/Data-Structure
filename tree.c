#include<stdio.h>
#include<stdlib.h>

struct n{
	int data;
	struct n*sol;
	struct n*sag;
	
};

struct n* ekle(struct n* agac,int x){
	if(agac==NULL){
		struct n* root=(struct n*)malloc(sizeof(struct n));
		root->sol=NULL;
		root->sag=NULL;
		root->data=x;
		return root;
	}
	
	if(agac->data < x){
		agac->sag=ekle(agac->sag,x);
		return agac;
	}

	else{
		agac->sol=ekle(agac->sol,x);
		return agac;
	}

}

int bul(struct n* agac,int aranan){
	
	if(agac==NULL){
		return -1;
	}
	
	if(agac->data == aranan){
		return 1;
	}
	
	if(bul(agac->sag,aranan) == 1){
		return 1;
	}
	
	if(bul(agac->sol,aranan) == 1){
		return 1;
	}
	
	return -1;
	
}

int max(struct n* agac){
	while(agac->sag != NULL){
		agac=agac->sag;
	}
	return agac->data;
}

int min(struct n* agac){
	while(agac->sol != NULL){
		agac=agac->sol;
	}
	return agac->data;
}

//küçükten büyüðe.........
void dolas(struct n* agac){
	if(agac==NULL){
		return;
	}

	dolas(agac->sol);
	printf("%d ",agac->data);
	dolas(agac->sag);
	
}

//büyükten küçüðe....... 
void dolasb(struct n* agac){
	if(agac==NULL){
		return;
	}
	
	dolasb(agac->sag);
	printf("%d ",agac->data);
	dolasb(agac->sol);
}


int main(){
	struct n* agac=NULL;
	agac=ekle(agac,12);
	agac=ekle(agac,200);
	agac=ekle(agac,190);
	agac=ekle(agac,213);
	agac=ekle(agac,56);
	agac=ekle(agac,24);
	agac=ekle(agac,18);
	agac=ekle(agac,27);
	agac=ekle(agac,28);
	
	dolas(agac);
	printf("\n");
	dolasb(agac);
	
	printf("\n");
	printf("arama sonucu 100: %d\n",bul(agac,100));
	printf("arama sonucu 24: %d\n",bul(agac,24));

	printf("max= %d min= %d",max(agac),min(agac));
	
	
	return 0;
}
