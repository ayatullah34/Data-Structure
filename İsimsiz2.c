#include <stdio.h>
#include <stdlib.h>
struct nodeStudent{
	int studentID;
	int midterm;
	struct nodeStudent *next;
};
struct nodeClass{
	int classID;
	double classMidtermAverage;
	struct nodeClass *next;
	struct nodeStudent *studentPtr;
};
void bastir(struct nodeClass *iter){
while(iter != NULL){
	printf("%d %.1f\n",iter->classID,iter->classMidtermAverage);
while(iter->studentPtr->next != NULL){
	printf("%d   %d\n",iter->studentPtr->studentID,iter->studentPtr->midterm);
	iter->studentPtr = iter->studentPtr->next;
}
iter=iter->next;}
}
void sinif(struct nodeClass *st){
int i=0;
st->classID = 1;
for(i = 0;i < 3;i++){
st->next = (struct nodeClass*) malloc(sizeof(struct nodeClass));
st->next->next = NULL;
st = st->next;
st->classID = i+2;}
}

int small(struct nodeClass *sm){
int counter=0;
int a;
int b;
int c;
int d;
struct nodeStudent *pointer;
pointer = sm->studentPtr;
while(pointer != NULL){
counter++;
pointer = pointer->next;
}
a = counter;
counter=0;
pointer=sm->next->studentPtr;
while(pointer!=NULL){
counter++;
pointer=pointer->next;
}
b=counter;
counter=0;
pointer=sm->next->next->studentPtr;
while(pointer!=NULL){
counter++;
pointer=pointer->next;
}
c = counter;
counter=0;
pointer=sm->next->next->next->studentPtr;
while(pointer!=NULL){
counter++;
pointer=pointer->next;
}
d=counter;
counter=0;
int smallest = a;
if(smallest > b){
	smallest = b;
}
else if(smallest>c){
	smallest = c;
}
else if(smallest>d){
	smallest=d;
}
return smallest;}

void sonuc(){
int ID=0;
int midterm;
int bol = 1000;
typedef struct nodeClass siniflar;

siniflar *classs;	

classs= (struct nodeClass*) malloc(sizeof(struct nodeClass));
sinif(classs);

struct nodeStudent *class1;

classs->studentPtr=(struct nodeStudent*) malloc(sizeof(struct nodeStudent));
class1 = classs->studentPtr;

struct nodeStudent *class2;

classs->next->studentPtr=(struct nodeStudent*) malloc(sizeof(struct nodeStudent));
class2 = classs->next->studentPtr;

struct nodeStudent *class3;

classs->next->next->studentPtr=(struct nodeStudent*)malloc(sizeof(struct nodeStudent));
class3 = classs->next->next->studentPtr;

struct nodeStudent *class4;

classs->next->next->next->studentPtr=(struct nodeStudent*)malloc(sizeof(struct nodeStudent));
class4 = classs->next->next->next->studentPtr;
while(ID != -1){
	scanf("%d",&ID);
if(ID==-1)
	break;
	scanf("%d",&midterm);
if(ID/bol==66){
class1->next = (struct nodeStudent*)malloc(sizeof(struct nodeStudent));
class1->studentID = ID;
class1->midterm = midterm;
class1->next->next = NULL;
class1=class1->next;
}
else if(ID/bol==77){
class2->next = (struct nodeStudent*)malloc(sizeof(struct nodeStudent));
class2->studentID = ID;
class2->midterm = midterm;
class2->next->next = NULL;
class2= class2->next;
}
else if(ID/bol==88){
class3->next=(struct nodeStudent*) malloc(sizeof(struct nodeStudent));
class3->studentID=ID;
class3->midterm=midterm;
class3->next->next = NULL;
class3=class3->next;
}
else if(ID/bol==99){
class4->next=(struct nodeStudent*) malloc(sizeof(struct nodeStudent));
class4->studentID=ID;
class4->midterm=midterm;
class4->next->next=NULL;
class4=class4->next;
}	
}
int smallest;
smallest=small(classs);
smallest=smallest-1;
//sorting and average
struct nodeStudent *temp=classs->studentPtr;
struct nodeClass *temp2=classs;
float average=0;
int a=0;
int i=0;
int countt=0;
while(temp2 != NULL){
	for(a=0;a<=i;a++){
while(temp->next != NULL){
if(temp->midterm < temp->next->midterm){
int tempid= temp->studentID;
	int tempmid= temp->midterm;
temp->studentID =temp->next->studentID;
 temp->midterm= temp->next->midterm;
temp->next->studentID = tempid;
temp->next->midterm =tempmid;
i++;
}
	temp=temp->next;}
		temp=temp2->studentPtr;
}
i=0;
temp2=temp2->next;
if(temp2 != NULL)
temp=temp2->studentPtr;
}
temp=classs->studentPtr;
temp2=classs;
while(temp2 != NULL){
while(temp->next!=NULL && countt < smallest){
average = average + temp->midterm;
countt++;
temp=temp->next;
}
average=average/(float)countt;
temp2->classMidtermAverage = average;
average=0;
countt=0;
temp2=temp2->next;
if(temp2!=NULL)
temp=temp2->studentPtr;
}
bastir(classs);}
int main()

{
	
	
sonuc();

	return 0;
}
