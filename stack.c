#include<stdio.h>
#include<stdlib.h>
int *dizi;
int boyut=2;
int tepe=0;

int pop(){
	if(dizi==NULL){
		printf("dizi bos");
		return -1;
	}
	if(tepe<=boyut/4){
		int i;
		int *dizi2=(int*)malloc(sizeof(int)*boyut/2);
		for(i=0;i<boyut;i++){
		dizi2[i]=dizi[i];
	}

	free(dizi);
	dizi=dizi2;
	boyut=boyut/2;
}
	return dizi[--tepe];
}

void push(int a){
	if(dizi==NULL){
	dizi=dizi=(int*)malloc(sizeof(int)*2);
	}
	if(tepe>=boyut){
		int i;
		int *dizi2=(int*)malloc(sizeof(int)*boyut*2);
		for(i=0;i<boyut;i++){
		dizi2[i]=dizi[i];
	}
		free(dizi);
		dizi=dizi2;
		boyut=boyut*2;
	}
	dizi[tepe++]=a;
	
}

void bastir(){
	printf("boyut: %d ",boyut);
	int i;
	for(i=0;i<tepe;i++){
		printf("%d ",dizi[i]);
	}
	printf("\n");
}

int main(){
	dizi=(int*)malloc(sizeof(int)*2);
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	bastir();
	printf("popped %d\n",pop());
	printf("popped %d\n",pop());
	printf("popped %d\n",pop());
	printf("popped %d\n",pop());
	printf("popped %d\n",pop());
	bastir();
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	push(70);
	push(80);
	push(90);
	push(100);
	bastir();
	
	
	return 0;
}
