


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

struct Node {
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
void printList(struct Node* head)
{
	struct Node* ptr = head;
	while (ptr)
	{
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}

	printf("NULL\n");
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


////////////////////////
void MoveNode(struct Node** destRef, struct Node** sourceRef)
{
	// if the source list empty, do nothing
	if (*sourceRef == NULL)
		return;
 
	struct Node* newNode = *sourceRef;  // the front source node
 
	*sourceRef = (*sourceRef)->next;	// Advance the source pointer
 
	newNode->next = *destRef;   	// Link the old dest off the new Node
	*destRef = newNode; 			// Move dest to point to the new Node
}



//---------------------BIRLEÞTIRME------------
struct Node* SortedMerge(struct Node* a, struct Node* b)
{
	// a dummy first node to hang the result on
	struct Node dummy;
	dummy.next = NULL;

	// Points to the last result node -- so tail->next is the place
	// to add new Nodes to the result.
	struct Node* tail = &dummy;

	while (1) 
	{
		// if either list runs out, use the other list
		if (a == NULL) 
		{
			tail->next = b;
			break;
		}
		else if (b == NULL) 
		{
			tail->next = a;
			break;
		}

		if (a->data <= b->data)
			MoveNode(&(tail->next), &a);
		else
			MoveNode(&(tail->next), &b);

		tail = tail->next;
	}

	return dummy.next;
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

struct node * root3;
struct node * a=root;
struct node * b=root2;
	root3=SortedMerge(&a,&b);
	//printAll(root3);
printList(root3);



	return 0;
}
