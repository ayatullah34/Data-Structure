#include <stdio.h>
#include <stdlib.h>


struct nodeClass {
	int classID;
	double classMidtermAverage;
	struct nodeClass* next;
	struct nodeStudent* studentPtr;
};
struct nodeStudent {
	int studentID;
	int midterm;
	struct nodeStudent* next;
};
struct nodeStudent* insertStudent(struct nodeStudent* head, int studentID, int midterm);
double getAvarage(struct nodeStudent* head,int minimum);
void printAll(struct nodeClass* head);




struct nodeStudent* insertStudent(struct nodeStudent* head, int studentID, int midterm)
{
	if (head == NULL) {
		struct nodeStudent* temp = (struct nodeStudent*)malloc(sizeof(struct nodeStudent));
		temp->midterm = midterm;
		temp->studentID = studentID;
		temp->next = NULL;
		head = temp;
		return head;
	}
	else if (midterm > head->midterm) {
		struct nodeStudent* temp = (struct nodeStudent*)malloc(sizeof(struct nodeStudent));
		temp->midterm = midterm;
		temp->studentID = studentID;
		temp->next = head;
		return temp;
	}
	else {
		struct nodeStudent* iter = head;
		while (iter->next != NULL && iter->next->midterm > midterm) {
			iter = iter->next;
		}
		struct nodeStudent* temp = (struct nodeStudent*)malloc(sizeof(struct nodeStudent));
		temp->next = iter->next;
		iter->next = temp;
		temp->midterm = midterm;
		temp->studentID = studentID;
		return head;
	}
}

double getAvarage(struct nodeStudent* head,int minimum)
{
	struct nodeStudent* temp = head;
	int i = 0;
	double totalMidterm = 0;
	double avarage = 0.0;
	while (i < minimum) {
		totalMidterm += temp->midterm;
		
		temp = temp->next;
		i++;
	}
	avarage = totalMidterm / minimum;
	return avarage;
}
void printAll(struct nodeClass* head) {

	int i;

	struct nodeStudent* temp;
	temp = head->studentPtr;

	struct nodeClass* classptr;
	classptr = head;

	printf("%d %.1f \n", head->classID, head->classMidtermAverage);


	for (i = 1; i <= 4; i++) {







		while (temp != NULL) {



			printf("%d   %d \n", temp->studentID, temp->midterm);


			temp = temp->next;


		}



		if (classptr->next != NULL) {
			classptr = classptr->next;

			temp = classptr->studentPtr;




			printf("%d %.1f \n", classptr->classID, classptr->classMidtermAverage);
		}

	}










}




void printClassList(struct nodeClass* head, int classId)
{
	struct nodeClass* temp = head;
	while (temp != NULL) {
		if (temp->classID == classId) {
			struct nodeStudent* iter = temp->studentPtr;
			while (iter != NULL) {
				printf("%d", iter->studentID);
				printf(" ");
				printf("%d \n", iter->midterm);

				iter = iter->next;
			}
		}
		temp = temp->next;
	}
}
int main()
{
	//int vvar;
	//int selection=0;	 	
	int count66 = 0, count77 = 0, count88 = 0, count99 = 0;
	int minimum;
	int StudentId;
	int Midterm;
	struct nodeClass* class1 = (struct nodeClass*)malloc(sizeof(struct nodeClass));
	struct nodeClass* class2 = (struct nodeClass*)malloc(sizeof(struct nodeClass));
	struct nodeClass* class3 = (struct nodeClass*)malloc(sizeof(struct nodeClass));
	struct nodeClass* class4 = (struct nodeClass*)malloc(sizeof(struct nodeClass));
	class1->classID = 1;
	class1->next = class2;
	class1->studentPtr = NULL;
	class2->classID = 2;
	class2->next = class3;
	class2->studentPtr = NULL;
	class3->classID = 3;
	class3->next = class4;
	class3->studentPtr = NULL;
	class4->classID = 4;
	class4->next = NULL;
	class4->studentPtr = NULL;
	/*struct nodeStudent head1 = class1->studentPtr;
	struct nodeStudent* head2 = class2->studentPtr;
	struct nodeStudent* head3 = class3->studentPtr;
	struct nodeStudent* head4 = class4->studentPtr;*/

	scanf("%d", & StudentId);

	while (StudentId != -1) {
		scanf("%d ",&Midterm);
		if (StudentId != -1) {
			if (StudentId / 1000 == 66) {
				class1->studentPtr = insertStudent(class1->studentPtr, StudentId, Midterm);
				count66++;
			}
			else if (StudentId / 1000 == 77) {
				class2->studentPtr = insertStudent(class2->studentPtr, StudentId, Midterm);
				count77++;
			}
			else if (StudentId / 1000 == 88) {
				class3->studentPtr = insertStudent(class3->studentPtr, StudentId, Midterm);
				count88++;
			}
			else if (StudentId / 1000 == 99) {
				class4->studentPtr = insertStudent(class4->studentPtr, StudentId, Midterm);
				count99++;
			}
		}
		scanf("%d" ,& StudentId);
	}

	minimum = count66 < count77 ? count66 : count77;
	minimum = (count88 < count99) ? ((count88 < minimum) ? count88 : minimum) : ((count99 < minimum) ? count99 : minimum);

	class1->classMidtermAverage = getAvarage(class1->studentPtr,minimum);
	class2->classMidtermAverage = getAvarage(class2->studentPtr,minimum);
	class3->classMidtermAverage = getAvarage(class3->studentPtr,minimum);
	class4->classMidtermAverage = getAvarage(class4->studentPtr,minimum);


	printAll(class1);


	return 0;
}
