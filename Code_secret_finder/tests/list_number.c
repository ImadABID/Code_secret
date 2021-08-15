#include<stdio.h>
#include<stdlib.h>

#include "../headers/list_number.h"

int main(){

    struct list_number *lt = list_number_new();

    //printf("%s", list_number_to_str(lt));

    int *test_set = list_number_propose_for_test(lt);
    printf("%d %d %d %d\n", test_set[0], test_set[1], test_set[2], test_set[3]);
    free(test_set);

    return 0;
}