#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../headers/number.h"
#include "../headers/list_number.h"
#include "../headers/list_teammate.h"

int main(){
    struct number *nbr1 = number_new(1, 2.4, 1, NULL, NULL, NULL);
    struct number *nbr2 = number_new(2, 2.4, 1, NULL, NULL, NULL);

    number_insert_as_next(nbr1, nbr2);

    
    char *line = malloc(400*sizeof(char));
    number_to_str(number_get_prev(nbr2), line);
    printf("%s\n", line);

    number_to_str(number_get_next(nbr1), line);
    printf("%s\n", line);
    free(line);
    

    return 0;
}