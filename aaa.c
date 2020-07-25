#include<stdio.h>
#include<stdlib.h>

int counter=1;
struct node *global_head=NULL;

struct node{
struct node *sol;
struct node *sag;
int ID;
int grade;
};



struct node *insert(struct node *tree,int n,int m)
{
	if(tree==NULL)
	{
		struct node *root=(struct node*)malloc(sizeof(struct node));
		root->sag=NULL;
		root->sol=NULL;
		root->ID=n;
		root->grade=m;
		return root;
	}

		if(tree->grade<m)
		{
			tree->sag=insert(tree->sag,n,m);
			return tree;
		}
			tree->sol=insert(tree->sol,n,m);
			return tree;
		
}

void traverse(struct node *tree)//inorder walking
{
	if(tree==NULL)
	return;
	
	traverse(tree->sol);
	printf("%d %d\n",tree->ID,tree->grade);
	traverse(tree->sag);
}

int height(struct node *node)
{
	if(node==NULL)
	return 0;
	
	else
	{
		int lheight=height(node->sol);
		int rheight=height(node->sag);

		if(lheight>rheight)
		return (lheight+1);
	
		else 
		return (rheight+1);
	}
}

struct node * find_parent(struct node * root)
{
	struct node *iter=global_head;
	
	if(iter==root)
	{
		return NULL;
	}

	while(iter->sol!=root && iter->sag!=root)
	{
		if(iter->grade > root->grade)
		{
			iter=iter->sol;
		}
		else
		{
			iter=iter->sag;
		}
	}
	return iter;
}

void printGivenLevel(struct node * root,int level)
{
	struct node *pe;
	if(root==NULL) 
	return;

	if(level==1)
	{
	printf("%d %d ",root->ID,root->grade);
	pe=find_parent(root);
		
		if(pe!=NULL)
		{
			if(pe->sol==root)
			{
				printf("(%d L) ",pe->grade);
			}
			else
			{
				printf("(%d R) ",pe->grade);
			}
		}
			
	return;
	}
	
	else if(level>1)
	{
	printGivenLevel(root->sol,level-1);
			//printf("(%d L) ",root->grade);

	printGivenLevel(root->sag,level-1);
			//printf("(%d R) ",root->grade);	
	}
return;	
}
void printLevelOrder(struct node *root)
{
	int h=height(root);
	int i;

	for(i=1;i<=h;i++)
	{
		printGivenLevel(root,i);
		printf("\n");
	}
}









int main(){
struct node *tree=NULL;
int grade,id;

//int counter=0;

while(1)
{
	scanf("%d%d",&id,&grade);
	if(id==-1 && grade==-1){break;}
	tree=insert(tree,id,grade);
	//counter++;
}

global_head=tree;

traverse(tree);
printf("\n");
printLevelOrder(tree);

return 0;}
