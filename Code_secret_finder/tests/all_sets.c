#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "../headers/list_number.h"

int main(){
 
    struct list_number *lnbr = list_number_new();
    int attempt = 0;
    int *test_set = malloc(4*sizeof(int));

    char first_number = 1;
    printf("#ifndef __ALL_SETS__H__\n#define __ALL_SETS__H__\nint ALL_SETS[][4]={");
    for(int i1 = 0; i1<10; i1++){
        test_set[0] = i1;
        for(int i2 = 0; i2<10; i2++){
            if(i2 != i1){
                test_set[1] = i2;
                for(int i3 = 0; i3<10; i3++){
                    if(i3 != i2 && i3 != i1){
                        test_set[2] = i3;
                        for(int i4 = 0; i4<10; i4++){
                            if(i4 != i3 && i4 != i2 && i4 != i1){
                                test_set[3] = i4;
                                if(!list_number_already_tested_no_order(lnbr, test_set)){
                                    if(!first_number){
                                        printf(",\n\t");
                                    }else{
                                        printf("\n\t");
                                        first_number = 0;
                                    }
                                    list_number_register_attempt(lnbr, test_set, 1.6);
                                    printf("{%d, %d, %d, %d}", test_set[0], test_set[1], test_set[2], test_set[3]);
                                    attempt++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("\n};\n#endif");
    free(test_set);
    list_number_free(lnbr);
    return 0;
}