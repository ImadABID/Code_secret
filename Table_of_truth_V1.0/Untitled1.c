#include<stdio.h>
#include<stdlib.h>

int sustraction(void *p);
int pr();

int main(){
	int *p;
	*p=pr();
	
	printf("%d",*p);
	
	return 0;
}

int pr(){
//	printf("Imad");
	return 4;
}

int sustraction(void *p){
	
	return 1;
}
