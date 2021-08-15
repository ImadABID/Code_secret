#include<stdio.h>
#include<stdlib.h>

#include "../headers/list_number.h"

int main(){

    struct list_number *lt = list_number_new();

    printf("%s", list_number_to_str(lt));

    return 0;
}