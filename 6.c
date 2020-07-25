#include <stdio.h>
#include <stdlib.h>


struct node* rightRotate(struct node* y);
struct node* newNode(int x);
struct node* leftRotate(struct node* x);
struct node* insert(struct node* node,int data);



int max(int a, int b);
int getBalance(struct node* N);
int height(struct node* N);
int heightoftree(struct node* node);




void deleteTree(struct node* dlt);
void printGivenLevel(struct node* root, int level, int islftrgt, int rootdata);
void printLevelOrder(struct node* root);

struct node{
	
	int data;
	
	struct node* left;
	
	struct node* right;
	
	int height;

}; 

struct node* newNode(int y)

{

struct node* nw=(struct node*)malloc(sizeof(struct node));
nw->data=y;

nw->left=nw->right=NULL;
nw->height=1;

return nw;


}

struct node*rightRotate(struct node*z){

struct node*W=z->left;

struct node*R=W->right;
W->right=z;
z->left=R;
z->height=max(height(z->left),height(z->right))+1;
W->height=max(height(W->left),height(W->right))+1;


return W;
}



struct node* leftRotate(struct node* W){
struct node* z = W->right;
struct node* P= z->left;

z->left=W;

W->right=P;

W->height=max(height(W->left),height(W->right))+1;

z->height=max(height(z->left),height(z->right))+1;


return z;

}


struct node* insert(struct node* r,int data){

if (r==NULL)
	return(newNode(data));

if (data<r->data)
	r->left = insert(r->left, data);

else if (data > r->data)
	r->right = insert(r->right, data);
else  
	return r;
	
r->height = 1 + max(height(r->left),
height(r->right));
int balance = getBalance(r);

if (balance>1 && data < r->left->data)
return rightRotate(r);
if (balance<-1 && data > r->right->data)
return leftRotate(r);
if (balance>1 && data>r->left->data)
{
r->left=leftRotate(r->left);

return rightRotate(r);
	
}
if (balance<-1&&data<r->right->data)
{
r->right=rightRotate(r->right);

return leftRotate(r);
}

return r;
}


struct node*getElement(struct node*g){
	int data = 0;

while(data != -1)
{
	scanf("%d", &data);

if (data==-1)
{
break;}

	g= insert(g, data);}
	return g;
}

int max(int a,int b){
	
	return (a > b) ? a : b;

}

int getBalance(struct node* m){
if (m==NULL)
	return 0;

return height(m->left) - height(m->right);

}




int height(struct node*m)
{
	if (m== NULL)
		return 0;
	return m->height;
}
void printLevelOrder(struct node* root){
int a=heightoftree(root);
int k;
for (k=1;k<=a;k++){
	if (root == NULL){
			break;
}
	printGivenLevel(root,k,2,root->data);
	printf("\n");
}
}

void printGivenLevel(struct node* root, int l, int er, int rootdata){
	if(root==NULL)
		return;

if (l==1&&(er==0 || er==1)){
	if(er==0){
	printf("%d (%d L) (%d B) ",root->data,rootdata,getBalance(root));
}
else if(er==1){
	printf("%d (%d R) (%d B) ", root->data,rootdata,getBalance(root));
}
}
if (l==1&&(er==2))
	printf("%d (%d B)", root->data,getBalance(root));

else if (l>1){
printGivenLevel(root->left,l-1,0,root->data);
printGivenLevel(root->right,l-1,1,root->data);
}
}

void deleteTree(struct node* re){
	if(re!=NULL){
		
	deleteTree(re->left);
	
	
	deleteTree(re->right);
	
	
	free(re);
}
}
int heightoftree(struct node* node){
	
	if(node==NULL)
		return 0;
	
	else{
		
	int solheight = heightoftree(node->left);
	
	
	int sagheight = heightoftree(node->right);
	
	if(solheight>sagheight)
		return(solheight + 1);
	else return(sagheight + 1);
}

}

int main(){
struct node*tree=NULL;
tree=getElement(tree);
printLevelOrder(tree);
deleteTree(tree);
return 0;
}
