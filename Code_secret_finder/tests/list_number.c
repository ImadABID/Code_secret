#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "../headers/list_number.h"

int main(){

    srand(time(NULL));

    struct list_number *lnbr = list_number_new();

    double score=0;
    int attempt = 1;
    
    char dicover = 0;
    int *test_set = malloc(4*sizeof(int));
    char *status = malloc(1000 * sizeof(char));

    while(score != 4){

        list_number_to_str_in_1_line(lnbr, status);
        printf("%s\n", status);

        list_number_decide_code(lnbr, test_set);

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