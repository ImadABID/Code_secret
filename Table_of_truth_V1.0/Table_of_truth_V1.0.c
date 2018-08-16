#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define E 4
#define PE 10

#define P 10000

/********************************************Structures*************************************************************/


/********************************************Variables Globales*****************************************************/
int TV[E][P];
int T_PE[PE];
int PAdmis[P];

/********************************************Prototypes*************************************************************/
void TableOfTruth();

void RemplissageDeT_PE();
void RempissageDePAdmis();

int puissance(int base,int puiss);

void remplissage2(int c, int cp);
void remplissage1(int c);
void remplissage0();
void correctionDeZero();

void EliminationDeRepitition();
	
void Presentation();
void LS();


/********************************************Fonction Main**********************************************************/
int main(){
	TableOfTruth();
	

	Presentation();


	return 0;
}
/********************************************Fonctions**************************************************************/
void TableOfTruth(){
	
	RemplissageDeT_PE();
	RempissageDePAdmis();

	
	remplissage0();
	correctionDeZero();

	EliminationDeRepitition();


}

					/*-----------------------------------------------*/					
void RemplissageDeT_PE(){
	int i;
	for(i=0;i<PE;i++){
		T_PE[i]=i;
	}
}

					/*-----------------------------------------------*/
void RempissageDePAdmis(){
	int i;
	for(i=0;i<P;i++){
		PAdmis[i]=1;
	}
}
					
					/*-----------------------------------------------*/
void remplissage2(int c, int cp){
	int iER=cp,i;
	while(iER>10){ iER=iER-10; }
	
	for(i=cp*puissance(PE,c);i<(cp+1)*puissance(PE,c);i++){
		TV[c][i]=T_PE[iER];
	}	
}
					/*-----------------------------------------------*/
void remplissage1(int c){
	int s=0,nbr_cp=0;
	while(s<P){
		s=s+puissance(PE,c);
		nbr_cp++;
	}
	
	int cp;
	for(cp=0;cp<nbr_cp;cp++){
		remplissage2(c,cp);
	}
}
					/*-----------------------------------------------*/
void remplissage0(){
	int c;
	for(c=0;c<E;c++){
		remplissage1(c);
	}
}					

					/*-----------------------------------------------*/
int puissance(int base,int puiss){

	if(puiss==0) return 1;
	if(puiss==1) return base;
	
	int m=1;
	int i;
	for(i=0;i<puiss;i++){
		m=m*base;
	}
	
	return m;
}

					/*-----------------------------------------------*/
void correctionDeZero(){
	int j,i;
	for(i=0;i<E;i++){
		for(j=0;j<P;j++){
			if(TV[i][j]==-1) TV[i][j]=0;
		}	
	}
}
/*===========================================================================*/
void EliminationDeRepitition(){
	int i,j,z;
	for(j=0;j<P;j++){
		for(i=0;i<E;i++){
			for(z=0;z<E;z++){
				if((TV[i][j]==TV[z][j])&&(i!=z)) PAdmis[j]=0;
			}
		}
	}
}

/*===========================================================================*/
void Presentation(){
	int i,j,z=1;
	for(j=0;j<P;j++){
		if(PAdmis[j]==1){
			LS();
			printf("%d	",z); z++;
			for(i=0;i<E;i++){
			printf(" %d",TV[i][j]);
			}
		}

	}
	LS();
}
					/*-----------------------------------------------*/	
void LS(){
	printf("\n");
}
