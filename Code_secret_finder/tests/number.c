#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../headers/number.h"
#include "../headers/list_number.h"
#include "../headers/list_teammate.h"

int main(){
    struct number *nbr = number_new(12, 2.4, 1, NULL, NULL, NULL);
    char *line = number_to_str(nbr);
    printf("%s\n", line);
    free(line);
    return 0;
}