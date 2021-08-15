#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../headers/list_teammate.h"

int main(){

    printf("Testing list_teammate.h :");
    
    struct list_teammate *lt = list_teammate_new();
    
    list_teammate_register(lt, 1);
    list_teammate_register(lt, 1);
    list_teammate_register(lt, 2);
    list_teammate_register(lt, 2);
    list_teammate_register(lt, 2);
    list_teammate_register(lt, 0);

if(strcmp(list_teammate_to_str(lt),"list_teammate{\n\t{number:0, teammate_occasion_number:1}\n\t{number:1, teammate_occasion_number:2}\n\t{number:2, teammate_occasion_number:3}\n}")==0){
    printf(" ok\n");
}else{
    fprintf(stderr, "Error at : list_teammate\n");
    exit(-1);
}   
    return 0;
}