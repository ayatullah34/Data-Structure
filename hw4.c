#include<stdio.h>
#include<stdlib.h>

struct n *sabit=NULL;

struct n{
	int data;
	int id;
	struct n*sol;
	struct n*sag;
	
};

struct n* ekle(struct n* agac,int x,int id){
	if(agac==NULL){
		struct n* root=(struct n*)malloc(sizeof(struct n));
		root->sol=NULL;
		root->sag=NULL;
		root->data=x;
		root->id=id;
		return root;
	}
	
	if(agac->data < x){
		agac->sag=ekle(agac->sag,x,id);
		return agac;
	}

	else{
		agac->sol=ekle(agac->sol,x,id);
		return agac;
	}

}


//küçükten büyüðe.........
void dolas(struct n* agac){
	if(agac==NULL){
		return;
	}

	dolas(agac->sol);
	printf("%d %d\n",agac->id,agac->data);
	dolas(agac->sag);
	
}

//DÜÐÜM.........
int sira(struct n *node){
	
if(node == NULL){
	
	return 0;
}
	
else{
	int sol_sira,sag_sira;
	sol_sira=sira(node->sol);
	sag_sira=sira(node->sag);

if(sol_sira > sag_sira){
	return (sol_sira + 1);
}
	
else{
	return (sag_sira + 1);
}

}
}

struct n * aile(struct n * r){
	struct n *iter=sabit;
	
if(iter == r){
	
	return NULL;
}

while(iter->sol != r && iter->sag != r){

if(iter->data > r->data){
	iter=iter->sol;

}
else{
	
	iter=iter->sag;
		
}

}
	
	return iter;

}

void sirasini_bastirma(struct n* r,int level){
	
struct n *dolas;

if(r == NULL){
	return;

}

if(level == 1){
	
printf("%d %d ",r->id,r->data);

dolas=aile(r);
		
if(dolas != NULL){
	
if(dolas->sol == r){

printf("(%d L) ", dolas->data);

}

else{
	
	printf("(%d R) ", dolas->data);
}
	
}
			
	return;
	

}
	
else if(level > 1) {
	//sol
	sirasini_bastirma(r->sol,level-1);
	//sað
	sirasini_bastirma(r->sag,level-1);	
	
}
	return;	

}


void sira_yazdirma(struct n *r) {
	int s,i;
	s = sira(r);
	
for( i=1 ; i <= s; i++){
	
sirasini_bastirma(r,i);
printf("\n");
	
}

}

int main(){
	struct n* agac=NULL;
	int x=0;
	int id;
	scanf("%d %d",&id,&x);
	while(id != -1 || x != -1){
	agac=ekle(agac,x,id);
	scanf("%d %d",&id,&x);
	}
	sabit=agac;
	
	dolas(agac);
	printf("\n");
	
	sira_yazdirma(agac);


	
	
	
	return 0;
}
