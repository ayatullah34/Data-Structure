#include<stdio.h>
#include<stdlib.h>

struct n{
	
	int data;
	struct n *next;
};



int pop(struct n **pptr)
{
 struct n *root = *pptr;
 if (root == NULL) {
 	printf("stack is empty\n");
  return -1;
 }
 struct n* iter = root;
 if (root && iter->next == NULL) {
  int a = iter->data;
  free(iter);
  *pptr = NULL;
  return a;
 }

 
 
 while (iter->next->next != NULL)
          iter = iter->next;
  iter->next->next == NULL;
   int a = iter->next->data;
   free(iter->next);
   iter->next = NULL;
   return a;
}


struct n *push(struct n* root,int a){
	
	if(root==NULL){
		root=(struct n*)malloc(sizeof(struct n));
		root->data=a;
		root->next=NULL;
		
		return root;
	}
	
	struct n*iter=root;
	while(iter->next != NULL){
		iter=iter->next;
	}
	
	struct n*temp=(struct n*)malloc(sizeof(struct n));
	temp->data=a;
	temp->next=NULL;
	iter->next=temp;
	
	return root;
}

int main(){

struct n*s=NULL;
	s=push(s,10);
	s=push(s,20);
	//bastir(s);
	//fflush(stdout);
	printf("%d->",pop(&s));
	s=push(s,30);
	printf("%d->\n",pop(&s));
	printf("%d->\n",pop(&s));
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
		s=push(s,20);
printf("%d\n",pop(&s));
	s=push(s,20);
		s=push(s,00);
			s=push(s,40);
				s=push(s,30);
			printf("%d->",pop(&s));		
printf("%d->",pop(&s));
printf("%d->",pop(&s));

return 0;
}
