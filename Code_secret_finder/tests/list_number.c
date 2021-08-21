#include<stdio.h>
#include<stdlib.h>

#include "../headers/list_number.h"

int main(){

    struct list_number *lnbr = list_number_new();
    
    char *str = malloc(20*400*sizeof(char));
    
    list_number_to_str(lnbr, str);
    printf("%s\n", str);
    
    int *attempt = (int *)malloc(4*sizeof(int));
    attempt[0] = 1; attempt[1] = 2; attempt[2] = 3; attempt[3] = 4;
    list_number_register_attempt(lnbr, attempt, 2.0);

    attempt[0] = 2; attempt[1] = 3; attempt[2] = 4; attempt[3] = 5;
    list_number_register_attempt(lnbr, attempt, 1.0);

    attempt[0] = 4; attempt[1] = 5; attempt[2] = 6; attempt[3] = 7;
    list_number_register_attempt(lnbr, attempt, 1.0);

    free(attempt);

    list_number_to_str(lnbr, str);
    printf("%s\n", str);

    free(str);

    /*
    int *test_set = malloc(4*sizeof(int));
    list_number_propose_for_test(lnbr, test_set);
    printf("%d %d %d %d\n", test_set[0], test_set[1], test_set[2], test_set[3]);

    list_number_propose_for_discovery(lnbr, 0, test_set);
    printf("%d %d %d %d\n", test_set[0], test_set[1], test_set[2], test_set[3]);

    free(test_set);
    */

    list_number_free(lnbr);

    return 0;
}