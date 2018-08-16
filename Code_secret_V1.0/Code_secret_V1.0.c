/*
Nom d'aplication:	Code Secret
Version:			1.0
Auteur:				Imad ABID
Date:				21/08/2016

*/
int test_entier(double r) {
 	int f ; f= 0;
    if (r==0) return 1 ;
    else{
	r= r<0 ? -r:r ;
 	while(r>f) f=f+1 ;
 	if(r==f) goto label ;
 	return 1 ;
 	label : return 2 ;
	}
 	
 }

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
                                     int tab1[4],tab2[4],essaye[4] ;
int main(int argc, char *argv[]) {
	char* nom1[10],nom2[10] ;
	double q ;
	int i,test,ne,e,ep ; test=0; ne=0 ; ep=0 ; e=0 ;
	


            //page 1
	printf("                                      ABID Softwar                                    \n") ;
	printf("                            your life is easy with our programs                        \n") ;
	printf("_______________________________________________________________________________________\n") ;
	printf("                                      CODE SECRET \n") ;
	printf("                                        ________                                       \n") ;
	printf("                                        ecrivez votre nom:                             \n") ;
	printf("                                            "); scanf("%s",&nom1) ;
    
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                                            %s\n",nom1);
    printf("                                 _________________________\n") ;
	printf("                                 entrez votre code scret :     \n") ;
	printf("                                          ") ; scanf("%d",&tab1[0]) ;

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                            %S\n",nom1); 
    printf("                                 _________________________\n") ;
	printf("                                 entrez votre code scret :     \n") ;
	printf("                                          *") ; scanf("%d",&tab1[1]) ;

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                            %s\n",nom1);
    printf("                                 _________________________\n") ;
	printf("                                 entrez votre code scret :     \n") ;
	printf("                                          **") ; scanf("%d",&tab1[2]) ;

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                            %s\n",nom1);
    printf("                                 _________________________\n") ;
	printf("                                 entrez votre code scret :     \n") ;
	printf("                                          ***") ; scanf("%d",&tab1[3]) ;

	printf("                                 _________________________\n") ;
	
	test=0;
	
	if(tab1[0]>9) test=1 ;
	if(tab1[0]<0) test=1 ;
	
	if(tab1[1]>9) test=1 ;
	if(tab1[1]<0) test=1 ;
	
	if(tab1[2]>9) test=1 ;
	if(tab1[2]<0) test=1 ;
	
	if(tab1[3]>9) test=1 ;
	if(tab1[3]<0) test=1 ;
	
	
	if(tab1[0]==tab1[1]) test=1 ;
	if(tab1[0]==tab1[2]) test=1 ;
	if(tab1[0]==tab1[3]) test=1 ; 
	if(tab1[1]==tab1[2]) test=1 ;
	if(tab1[1]==tab1[3]) test=1 ;
	if(tab1[2]==tab1[3]) test=1 ;
	
	
	if(test==1) {printf("%s! il y a un probleme, redemarez le programme pour le corection",nom1) ; scanf("%d",ne); }
	else{
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
			printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
			printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
			printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
			printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
			printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
			printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
	
	printf("                                      ABID Softwar                                    \n") ;
	printf("                            your life is easy with our programs                        \n") ;
	printf("_______________________________________________________________________________________\n") ;
	printf("                                      CODE SECRET \n") ;
	printf("                                        ________                                       \n") ;
	printf("                                        ecrivez votre nom:                                        \n") ;
    printf("                                          ");scanf("%s",&nom2) ;
    
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                            %s\n",nom2);
    printf("                                 _________________________\n") ;
	printf("                                 entrez votre code scret :     \n") ;
	printf("                                          ") ; scanf("%d",&tab2[0]) ;

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                            %s\n",nom2);
	printf("                                 _________________________\n") ;
	printf("                                 entrez votre code scret :     \n") ;
	printf("                                          *") ; scanf("%d",&tab2[1]) ;

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                            %S\n",nom2);
    printf("                                 _________________________\n") ;
	printf("                                 entrez votre code scret :     \n") ;
	printf("                                          **") ; scanf("%d",&tab2[2]) ;

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("                                            %s\n",nom2);    
	printf("                                 _________________________\n") ;
	printf("                                 entrez votre code scret :     \n") ;
	printf("                                          ***") ; scanf("%d",&tab2[3]) ;

	printf("                                 _________________________\n") ;
	


	
	test=0;
	
	if(tab2[0]>9) test=1 ;
	if(tab2[0]<0) test=1 ;
	
	if(tab2[1]>9) test=1 ;
	if(tab2[1]<0) test=1 ;
	
	if(tab2[2]>9) test=1 ;
	if(tab2[2]<0) test=1 ;
	
	if(tab2[3]>9) test=1 ;
	if(tab2[3]<0) test=1 ;
	
	
	if(tab2[0]==tab2[1]) test=1 ;
	if(tab2[0]==tab2[2]) test=1 ;
	if(tab2[0]==tab2[3]) test=1 ; 
	if(tab2[1]==tab2[2]) test=1 ;
	if(tab2[1]==tab2[3]) test=1 ;
	if(tab2[2]==tab2[3]) test=1 ;  
	
	
	if(test==1) {printf("%s! il y a un probleme, redemarez le programme pour le corection",nom2) ; scanf("%d",ne) ;}
	if(test!=1){
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
			printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
			printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
			printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
			printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
			printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
			printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		
	printf("Tour     Possibilites                           %s  E / EP        %s E / EP \n",nom1,nom2);
	printf("______________________________________________________________________________________\n");
	
		while(ep!=4){
			ne=ne+1; q=ne; q=q/2;
			
			if(test_entier(q)==1) {
	printf("%s :\n",nom1);
	printf("                         tentative: %d\n",(ne+1)/2) ;
	           for(i=0;i<4;i++) { printf("              "); scanf("%d",&essaye[i]) ;} 
				
				e=0;ep=0;
				
				if(essaye[0]==tab2[0]) { e=e+1;ep=ep+1 ;}
				if(essaye[0]==tab2[1]) { e=e+1; }  
				if(essaye[0]==tab2[2]) { e=e+1; }
				if(essaye[0]==tab2[3]) { e=e+1; }
				if(essaye[1]==tab2[0]) { e=e+1; }
				if(essaye[1]==tab2[1]) { e=e+1;ep=ep+1 ;}
				if(essaye[1]==tab2[2]) { e=e+1; }
				if(essaye[1]==tab2[3]) { e=e+1; }
				if(essaye[2]==tab2[0]) { e=e+1; }
				if(essaye[2]==tab2[1]) { e=e+1; }
				if(essaye[2]==tab2[2]) { e=e+1;ep=ep+1 ;}
				if(essaye[2]==tab2[3]) { e=e+1; }
				if(essaye[3]==tab2[0]) { e=e+1; }
				if(essaye[3]==tab2[1]) { e=e+1; }
				if(essaye[3]==tab2[2]) { e=e+1; }
				if(essaye[3]==tab2[3]) { e=e+1;ep=ep+1 ;}
	printf("                                                         %d   %d \n",e,ep) ;
	printf("______________________________________________________________________________________\n");
			}
			if(test_entier(q)==2) {
				e=0;ep=0;
	printf("%s :\n",nom2);
	printf("                         tentative: %d\n",ne/2) ;
	           for(i=0;i<4;i++) { printf("              "); scanf("%d",&essaye[i]) ;} 
				
				if(essaye[0]==tab1[0]) { e=e+1;ep=ep+1 ;}
				if(essaye[0]==tab1[1]) { e=e+1; }  
				if(essaye[0]==tab1[2]) { e=e+1; }
				if(essaye[0]==tab1[3]) { e=e+1; }
				if(essaye[1]==tab1[0]) { e=e+1; }
				if(essaye[1]==tab1[1]) { e=e+1;ep=ep+1 ;}
				if(essaye[1]==tab1[2]) { e=e+1; }
				if(essaye[1]==tab1[3]) { e=e+1; }
				if(essaye[2]==tab1[0]) { e=e+1; }
				if(essaye[2]==tab1[1]) { e=e+1; }
				if(essaye[2]==tab1[2]) { e=e+1;ep=ep+1 ;}
				if(essaye[2]==tab1[3]) { e=e+1; }
				if(essaye[3]==tab1[0]) { e=e+1; }
				if(essaye[3]==tab1[1]) { e=e+1; }
				if(essaye[3]==tab1[2]) { e=e+1; }
				if(essaye[3]==tab1[3]) { e=e+1;ep=ep+1 ;}
	printf("                                                                               %d   %d \n",e,ep) ;
	printf("______________________________________________________________________________________\n");		
			}
		}
		
		//page4
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		
		if(test_entier(q)==1) {
		printf("                                 %s est reussi \n                                 votre score est : %d",nom1,101-ne) ;
		printf("\n                                 tentative: %d ",(ne+1)/2) ;}
		if(test_entier(q)==2) {
		printf("                                 %s est reussi \n                                 votre score est : %d",nom2,102-ne) ;		
	    printf("\n                                 tentative: %d",ne/2 );}
		
		printf("\n\n\n\ncode secret de %s: %d%d%d%d                       code secret de %s : %d%d%d%d",nom1,tab1[0],tab1[1],tab1[2],tab1[3],nom2,tab2[0],tab2[1],tab2[2],tab2[3]);
		
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
		
		
		printf("Edit By Imad ABID                                                    ABID Softwar") ;
		
		
		
		
		

		
		scanf("%d",ne) ;
		
		
		
	}}
	

	
	return 0;
}
