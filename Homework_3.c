#include <stdio.h>
#include <stdlib.h>

struct nodeFB
{
	int id;
	int age;
	struct nodeFB *next;
};

struct nodeGS
{
	int id;
	struct nodeGS *next;
};

struct node {
int data;
struct node *next;
};


///////////////---------------- PRINT GS--------------
void printGS(struct nodeGS * r){
	while(r!=NULL){
		printf("Id:%d\n",r->id);
		r= r->next;
	}
}
///////////////----------------PRINT FB--------------
void printFB(struct nodeFB * f){
	while(f!=NULL){
		printf("Id:%d\t",f->id);
		printf("Age:%d\n",f->age);
		f= f->next;
		
	}
}
/////////////-------------PRINT ALL----------------
void printAll(struct nodeFB *g){
	while(g!=NULL){
		printf("Id:%d Age:%d\t",g->id,g->age);
		printf("Age:%d\n",g->age);
		g=g->next;
	}
	
}

/*
void printFB(struct nodeFB *);
void printGS(struct nodeGS *);
void printAll(struct nodeFB *);  
*/

///////////////----------------SIRALAMA GS--------------

struct nodeGS * ekleSiraliGS(struct nodeGS * r,int id){
	if(r==NULL){ // linklist bossa
		r=(struct nodeGS *)malloc(sizeof(struct nodeGS));
		r->next = NULL;
		r->id = id;
		return r;
	}
	if(r->id < id){ // ilk elemandan buyuk durumu
			// root degisiyor
			struct nodeGS * temp = (struct nodeGS*)malloc(sizeof(struct nodeGS));
			temp -> id = id;
			temp -> next =r;
			return temp;
	}
	struct nodeGS * iter = r;
	while(iter->next != NULL && iter->next->id >id){
		iter= iter->next;
	}
	struct nodeGS * temp = (struct nodeGS*)malloc(sizeof(struct nodeGS));
	temp->next = iter -> next;
	iter -> next = temp;
	temp -> id= id;
	return r;
}



///////////////----------------SIRALAMA FB--------------

struct nodeFB * ekleSiraliFB(struct nodeFB * r,int id){
	if(r==NULL){ // linklist bossa
		r=(struct nodeFB *)malloc(sizeof(struct nodeFB));
		r->next = NULL;
		r->id = id;
		return r;
	}
	if(r->id > id){ // ilk elemandan kucuk durumu
			// root degisiyor
			struct nodeFB * temp = (struct nodeFB*)malloc(sizeof(struct nodeFB));
			temp -> id = id;
			temp -> next =r;
			return temp;
	}
	struct nodeFB * iter = r;
	while(iter->next != NULL && iter->next->id <id){
		iter= iter->next;
	}
	struct nodeFB * temp = (struct nodeFB*)malloc(sizeof(struct nodeFB));
	temp->next = iter -> next;
	iter -> next = temp;
	temp -> id= id;
	return r;
}

//---------------------BIRLEÞTIRME------------
void concatenate(struct node* list_1, struct node* list_2){ //parametrelere dikkat
if(list_1 == NULL)
list_1 = list_2;
else {
// Birinci listenin son düðümünü last olarak bulmak için
struct node *last=list_1;
while(last -> next != list_1)
last = last -> next;
last->next=list_2; //Birinci listenin sonu ikinci listenin baþýna baðlandý
// Ýkinci listenin son düðümünü last olarak bulmak için
last=list_2;
while(last -> next != list_2)
last = last -> next;
last->next=list_2; //Ýkinci listenin sonu birinci listenin baþýna baðlandý
}
}


int main()
{
	
////////////-------FB--------
int age;
struct nodeFB * root2;
//int j=0;
int idss;
root2= NULL;
while(idss!=-1 || age!=-1){
	root2=ekleSiraliFB(root2,idss);
	scanf("%d %d",&idss,&age);
}

printFB(root2);
	
//////////------------GS
	struct nodeGS * root;
	int ids;
	//int i=0;
	root = NULL;
	while(ids!=-1){
		root=ekleSiraliGS(root,ids);
		scanf("%d",&ids);
}
printGS(root);

/////////-----------ALL-------
	struct node * root3;
		struct node * a=root;
			struct node *b= root2;
	root3=concatenate(a,b);
	printAll(root3);






	return 0;
}
