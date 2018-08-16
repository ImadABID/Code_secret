/*
Nom d'aplication:	Code Secret
Version:			2.1
Auteur:				Imad ABID
Date:				07/07/2017
Nouveautés:			-Programation Modulaire facile à dévloppé.
					-Interface Colorée plus organisée.
					-Jeux sans redémarage de programme.
					-L'écriture de Password est masquée.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


/********************************************Structures*************************************************************/
typedef struct structure{
	char nom[56];
	char password[32];
}typeofPlayer;

/********************************************Variables Globales*****************************************************/
char MonTemps[128];
typeofPlayer player1;
typeofPlayer player2;
int PasswordTaille = 4;
char PasswordProposed[32];
int t;
int EP;
int E;

/********************************************Prototypes*************************************************************/

void Logo();
void DureeAttendre(int s);
void TempsActualise();
int TestTime();

void LireInformation0();
void LireInformation1(int nbrPlayer);
void lirePassword(int nbrPlayer);
int TestPassword(int nbrPlayer);
void RelirePassword(int nbrPlayer);

void SurfaceDeJeux();
void print();
int PasswordProposedTest(int nbrPlayer);
void Centre(int espace, char mot[256]);
int LN();
void LS();
void L1();
void L2();
void L3();

void result();
void winner(int nbrPlayer);
void matchNull();

/********************************************Fonction Main**********************************************************/
int main(){
	
	Logo();
	
	LireInformation0();
	SurfaceDeJeux();

	return 0;
}
/********************************************Fonctions**************************************************************/

void Logo(){
	int i;
	system("COLOR F0");

	system("cls");
	i=0;
	while(i<11){
		printf("\n");
		i++;
	}
	while(i<40){
		printf(" ");
		i++;
	}
	printf("CODE");
	
	DureeAttendre(2);
	system("cls");
	i=0;
	while(i<11){
		printf("\n");
		i++;
	}
	while(i<45){
		printf(" ");
		i++;
	}
	printf("SECRET");
	
	
	DureeAttendre(2);
	system("cls");
	i=0;
	while(i<10){
		printf("\n");
		i++;
	}
	while(i<40){
		printf(" ");
		i++;
	}
	printf("CODE SECRET");
	DureeAttendre(3);
	
	
	system("cls");
	i=0;
	while(i<10){
		printf("\n");
		i++;
	}
	while(i<40){
		printf(" ");
		i++;
	}
	printf("IMAD ABID");
	DureeAttendre(3);
}

void DureeAttendre(int s){
	int i;
	for(i=0;i<s;i++){
		TestTime();
	}
}

void TempsActualise(){
	time_t t;
	t=time(NULL);	
	strcpy(MonTemps,ctime(&t));
}

int TestTime(){
	time_t t;
	t=time(NULL);
	
	char LastTime[128];
	strcpy(LastTime,ctime(&t));
	

	
	int n=0;
	while(1){
		TempsActualise();
		if(strcmp(LastTime,MonTemps)!=0){
			return 0;
		}	
	}
	
	return -1;
}


/*=========================================================================================*/
void LireInformation0(){
	system("COLOR 5F");
	LireInformation1(1);
	LireInformation1(2);
}
						/*__________________________________________________*/
void LireInformation1(int nbrPlayer){
	system("cls");
	printf("This Surface is dedicated to player number %d:\n",nbrPlayer);
	printf("_____________________________________________\n\n\n");
	
	if(nbrPlayer==1){
		printf("\t\tWrite your name:"); gets(player1.nom);
		printf("\n\t\tWrite your password:"); lirePassword(1);
		while(TestPassword(1)==-1){
			RelirePassword(1);
		}
	}

	if(nbrPlayer==2){
		printf("\t\tWrite your name:"); gets(player2.nom);
		printf("\n\t\tWrite your password:"); lirePassword(2);
		while(TestPassword(2)==-1){
			RelirePassword(2);
		}
	}
	
}

						/*__________________________________________________*/
void lirePassword(int nbrPlayer){
	int i ;
	if(nbrPlayer==1){
		for(i=0;i<PasswordTaille;i++){
			player1.password[i]=getch();
			printf("*");
		}	
	}
	
	if(nbrPlayer==2){
		for(i=0;i<PasswordTaille;i++){
			player2.password[i]=getch();
			printf("*");
		}	
	}
	
}

						/*__________________________________________________*/
int TestPassword(int nbrPlayer){
	
	int i,j;
	if(nbrPlayer==1){
		for(i=0;i<PasswordTaille;i++){
			for(j=0;j<PasswordTaille;j++){
				if(((player1.password[j]>'9')||(player1.password[j]<'0'))||((j!=i)&&(player1.password[j]==player1.password[i])) ) return -1;
			}
		}
	}
	if(nbrPlayer==2){
		for(i=0;i<PasswordTaille;i++){
			for(j=0;j<PasswordTaille;j++){
				if((player2.password[j]>'9')||(player2.password[j]<'0')||((j!=i)&&(player2.password[j]==player2.password[i])) ) return -1;
			}
		}
	}
	
	return 0;
}		
						
						/*__________________________________________________*/
void RelirePassword(int nbrPlayer){
	system("cls");
	system("COLOR CF");
	if(nbrPlayer==1){
		printf("%s! Your password isn't correct.\n",player1.nom);
		printf("\tWrite again your password:"); lirePassword(1);
	}
	if(nbrPlayer==2){
		printf("%s! Your password isn't correct.\n",player2.nom);
		printf("\tWrite again your password:"); lirePassword(2);
	}
	system("COLOR 5F");
}

/*=========================================================================================*/
void result(){
	int r;
	
	for(t=1;t<100;t++){
		r=LN();
		if(r==1) { winner(1); break; }
		if(r==2) { winner(2); break; }
		if(r==3) { matchNull(); break; }				 
	}
	matchNull();
}
						/*__________________________________________________*/
void winner(int nbrPlayer){
	system("cls");
	system("COLOR AF");
	int i ;
	for(i=0;i<16;i++){
		printf("\n");
	}
	for(i=0;i<30;i++){
		printf(" ");
	}

	if(nbrPlayer==1){
		printf("The winner is: %s",player1.nom);
	}

	if(nbrPlayer==2){
		printf("The winner is: %s",player2.nom);
	}		
	
	printf("\n\n");
	for(i=0;i<32;i++){
		printf(" ");
	}
	printf("PRESS ANY KEY TO REPLAY!"); getch(); SurfaceDeJeux();
}

						/*__________________________________________________*/
void matchNull(){
	system("cls");
	system("COLOR 0F");
	int i ;
	for(i=0;i<16;i++){
		printf("\n");
	}
	
	for(i=0;i<35;i++){
		printf(" ");
	}
	printf("Match Null");
	
		printf("\n\n");
	for(i=0;i<32;i++){
		printf(" ");
	}
	printf("PRESS ANY KEY TO REPLAY!"); getch(); SurfaceDeJeux();
	
}
/*=========================================================================================*/
void SurfaceDeJeux(){
	
	system("cls");
	system("COLOR 70");
	L1();L2();L3();
	
	result();

}

						/*__________________________________________________*/
void print(){
	int i;
	for(i=0;i<PasswordTaille;i++){
		PasswordProposed[i]=getch();
		printf("%c",PasswordProposed[i]);
	}
}

						/*__________________________________________________*/
int PasswordProposedTest(int nbrPlayer){

	int i,j;
	EP=0; E=0;
	
	print();
	

	if(nbrPlayer==1){
		for(i=0;i<PasswordTaille;i++){
			if(player2.password[i]==PasswordProposed[i]) EP++;	
			for(j=0;j<PasswordTaille;j++){
				if(player2.password[i]==PasswordProposed[j]) E++;
				 
			}		
		}
		if(strcmp(player2.password,PasswordProposed)==0) return 0;	
	}
	
	if(nbrPlayer==2){
		for(i=0;i<PasswordTaille;i++){
			if(player1.password[i]==PasswordProposed[i]) EP++;	
			for(j=0;j<PasswordTaille;j++){
				if(player1.password[i]==PasswordProposed[j]) E++;
				 
			}		
		}
		if(strcmp(player1.password,PasswordProposed)==0) return 0;	
	}

	return -1;
}
						/*__________________________________________________*/
void Centre(int espace, char mot[256]){
	int i,j;
	for(i=0;i<((espace-strlen(mot))/2);i++){
		printf(" ");
	}
	
	printf("%s",mot);
	j=i;
	for(i=0;i<espace-i-strlen(mot)-2;i++){
		printf(" ");
	}	
}					
						
						/*__________________________________________________*/
void LS(){
	int i;
	printf("\n");
	printf(" ");
	for(i=0;i<38;i++){ printf("-"); }
	printf("  ");
	for(i=0;i<38;i++){ printf("-"); }
	printf("\n");	
}
						/*__________________________________________________*/
void L1(){
	int i;
	for(i=0;i<38;i++){
		printf(" ");
	}
	printf("CODE SECRET");
	printf("\n");
	LS();
}

						/*__________________________________________________*/
void L2(){
	
	printf(" | ");
	Centre(36,player1.nom);
	printf("|  |");
	Centre(33,player2.nom);
	printf("    |");	
	
	LS();
}
						/*__________________________________________________*/
void L3(){
	
	printf(" |T |    Password Proposed    | E |EP |");
	printf(" ");
	printf(" |T |    Password Proposed    | E |EP |");
	
	LS();
}

						/*__________________________________________________*/
int LN(){
	int g1=-1, g2=-1;
	
	if(t<10) printf(" |%d |",t);
	else printf(" |%d|",t);
	
	printf("          ");
	g1=PasswordProposedTest(1);
	printf("           |");
	
	printf(" %d |",E);
	printf(" %d |",EP);
	
	if(t<10) printf("  |%d |",t);
	else printf("  |%d|",t);
	
	printf("          ");
	g2=PasswordProposedTest(2);
	printf("           |");
	
	printf(" %d |",E);
	printf(" %d |",EP);
	
	
	LS();
	//0 Code Correcte
	//-1 Code Incorrecte	
	if(g1==-1&&g2==-1)return 0;
	if(g1==0&&g2==-1) return 1;
	if(g2==0&&g1==-1) return 2;
	if(g1==0&&g2==0) return 3;	
	
}

