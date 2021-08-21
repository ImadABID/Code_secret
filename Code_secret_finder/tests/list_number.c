#include<stdio.h>
#include<stdlib.h>

#include "../headers/list_number.h"

int main(){

    struct list_number *lnbr = list_number_new();

    double score=0;
    int attempt = 1;
    
    char dicover = 0;
    int *test_set = malloc(4*sizeof(int));

    while(score != 4){
        if(dicover){
            list_number_propose_for_discovery(lnbr, 0, test_set);
            dicover = 0;
        }else{
            list_number_propose_for_test(lnbr, test_set);
            dicover = 1;
        }

        printf("Attempt %d\t%d%d%d%d\t",attempt,
            test_set[0], test_set[1],
            test_set[2], test_set[3]
        );
        scanf("%lf", &score);
        list_number_register_attempt(lnbr, test_set, score);

        attempt++;
    }

    free(test_set);

    list_number_free(lnbr);

    return 0;
}