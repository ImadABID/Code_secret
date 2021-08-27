#include<stdio.h>
#include<stdlib.h>

#include "../headers/teammate_path_list.h"

int main(){

    struct teammate_path_list *tpathl = teammate_path_list_init(2);
    teammate_path_list_print(tpathl);

    if(teammate_path_visited(tpathl, 2))
        printf("2 was visted\n");
    else
        printf("2 not visited yet\n");

    if(teammate_path_visited(tpathl, 7))
        printf("7 was visted\n");
    else
        printf("7 not visited yet\n");
    
    return 0;
}