#include <stdio.h>
#include <math.h>
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
	
	while(iter!=NULL){
		
		printf("%d %.1f\n",iter->classID,iter->classMidtermAverage);
		
			while(iter->studentPtr->next!=NULL){
				
				printf("%d   %d\n",iter->studentPtr->studentID,iter->studentPtr->midterm);
				iter->studentPtr = iter->studentPtr->next;
			}
			
			iter = iter->next;
	}
}



void sinif(struct nodeClass *st){
	
	int i=0;
	
	st->classID = 1;
	
	for(i = 0;i<3;i++){
	
	st->next = (struct nodeClass*) malloc(sizeof(struct nodeClass));
	st->next->next = NULL;
	st = st->next;
	st->classID = i+2;
	
}
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
	
	pointer = sm->next->studentPtr;
	
	while(pointer != NULL){
		counter++;
		pointer= pointer->next;
	}
	
	b = counter;
	
	
	counter=0;
	
	pointer = sm->next->next->studentPtr;
	
	while(pointer != NULL){
		counter++;
		pointer=pointer->next;
	}
	
	c = counter;
	
	
	counter=0;
	

	pointer = sm->next->next->next->studentPtr;
	
	
	while(pointer != NULL){
		counter++;
		pointer =pointer->next;
	}
	
	d = counter;
	
	counter=0;
	
	int smallest = a;
	
	if(smallest>b){
		smallest = b;
	}
	
	else if(smallest > c){
		smallest = c;
	}
	
		else if(smallest > d){
		smallest = d;
	}
	
	
	return smallest;

	
}




void sonuc () {
	
	//Variables
	
	int id=0,midterm;
	int den = 1000;
	
	//Creating 4 Classes
	
	
	typedef struct nodeClass Classes;
	Classes *DSClassesiter;	
	DSClassesiter = (struct nodeClass*) malloc(sizeof(struct nodeClass));
	sinif(DSClassesiter);
	
	
	//Class 1
	
	struct nodeStudent *sttemp1;
	DSClassesiter->studentPtr = (struct nodeStudent*) malloc(sizeof(struct nodeStudent));
	sttemp1 = DSClassesiter->studentPtr;
	
	//Class 2
	
	struct nodeStudent *sttemp2;
	DSClassesiter->next->studentPtr = (struct nodeStudent*) malloc(sizeof(struct nodeStudent));
	sttemp2 = DSClassesiter->next->studentPtr;
	
	//Class 3
	
	struct nodeStudent *sttemp3;
	DSClassesiter->next->next->studentPtr = (struct nodeStudent*) malloc(sizeof(struct nodeStudent));
	sttemp3 = DSClassesiter->next->next->studentPtr;
	
	//Class 4
	
	struct nodeStudent *sttemp4;
	DSClassesiter->next->next->next->studentPtr = (struct nodeStudent*) malloc(sizeof(struct nodeStudent));
	sttemp4 = DSClassesiter->next->next->next->studentPtr;
	
	
	while(id!=-1){
		

		scanf("%d",&id);
		
		if(id == -1)
		break;
			
		scanf("%d",&midterm);
		
		
	
	if(id/den == 66){
			
		sttemp1->next = (struct nodeStudent*) malloc(sizeof(struct nodeStudent));
		sttemp1->studentID = id;
		sttemp1->midterm = midterm;
		sttemp1->next->next = NULL;
		sttemp1 = sttemp1->next;
		
		
	}
	
	
	else if(id/den == 77){
		
		sttemp2->next = (struct nodeStudent*) malloc(sizeof(struct nodeStudent));
		sttemp2->studentID = id;
		sttemp2->midterm = midterm;
		sttemp2->next->next = NULL;
		sttemp2 = sttemp2->next;
		
	}
	
	else if(id/den == 88){
		
		sttemp3->next = (struct nodeStudent*) malloc(sizeof(struct nodeStudent));
		sttemp3->studentID = id;
		sttemp3->midterm = midterm;
		sttemp3->next->next = NULL;
		sttemp3 = sttemp3->next;
		
	}
	
	else if(id/den == 99){
		
		sttemp4->next = (struct nodeStudent*) malloc(sizeof(struct nodeStudent));
		sttemp4->studentID = id;
		sttemp4->midterm = midterm;
		sttemp4->next->next = NULL;
		sttemp4 = sttemp4->next;
		
	}	
	}
	
	int smallest;
	
	smallest = small(DSClassesiter);
	smallest -= 1;
	
	//sorting and average
	
	struct nodeStudent *temp = DSClassesiter->studentPtr;
	struct nodeClass *temp2 = DSClassesiter;
	float average=0;
	
	int a=0,i=0,countt=0;
	
	
	while(temp2!=NULL){
	
		for(a=0;a<=i;a++){
	
			while(temp->next!=NULL){
		
				if(temp->midterm < temp->next->midterm){
			
					int tempid = temp->studentID;
					int tempmid = temp->midterm;
			
					temp->studentID = temp->next->studentID;
					temp->midterm = temp->next->midterm;
			
					temp->next->studentID = tempid;
					temp->next->midterm = tempmid;
					
					i++;
					
					}
			
							
				temp = temp->next;
			
				
			}
			
			
			
			
			temp = temp2->studentPtr;
		}
		
		i=0;
		
		
		
		temp2 = temp2->next;
		
		if(temp2!=NULL)
		temp = temp2->studentPtr;
		
		
		}
		
		
		
	temp = DSClassesiter->studentPtr;
	temp2 = DSClassesiter;
	
	while(temp2!=NULL){
		
		while(temp->next!=NULL && countt < smallest){
			
			average = average + temp->midterm;
			countt++;
			temp = temp->next;
		}
		
		average = average/(float)countt;
		temp2->classMidtermAverage = average;
		average = 0;
		countt = 0;
		
		temp2 = temp2->next;
		
		if(temp2!=NULL)
		temp = temp2->studentPtr;
		
	}
	

	
	
	bastir(DSClassesiter);

}



int main(){
	
	sonuc();
	
	return 0;
}
