#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

	time_t t;
	char LastTime[256];
	int i;

int main(){
	
	i=0;
	
	t=time(NULL);
	strcpy(LastTime,ctime(&t));
	
	printf("%s",LastTime);
	
	printf("%d",condition());
	
	
	


}

int condition(){
	char MonTime[256];
	
	while(1){
		strcpy(MonTime,ctime(&t));
		if(strcmp(MonTime,LastTime)!=0) return i;
		i++;
	}
	return -1;
}


