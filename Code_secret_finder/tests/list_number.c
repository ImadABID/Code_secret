#include<stdio.h>
#include<stdlib.h>

#include "../headers/list_number.h"

int main(){

    struct list_number *lnbr = list_number_new();

    char *str = malloc(20*200*sizeof(char));
    list_number_to_str(lnbr, str);
    printf("%s\n", str);
/*
    int *test_set = malloc(4*sizeof(int));

    list_number_propose_for_test(lnbr, test_set);
    printf("%d %d %d %d\n", test_set[0], test_set[1], test_set[2], test_set[3]);

    list_number_propose_for_discovery(lnbr, 0, test_set);
    printf("%d %d %d %d\n", test_set[0], test_set[1], test_set[2], test_set[3]);
    
    free(str);
    free(test_set);
*/
    return 0;
}