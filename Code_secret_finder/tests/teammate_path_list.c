#include<stdio.h>
#include<stdlib.h>

#include "../headers/teammate_path_list.h"

int main(){

    struct teammate_path_list *tpathl = teammate_path_list_init(2);
    teammate_path_list_print(tpathl);
    
    

    return 0;
}