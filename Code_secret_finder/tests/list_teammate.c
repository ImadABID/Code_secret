#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../headers/list_teammate.h"

int main(){

    printf("Testing list_teammate.h :");
    
    struct list_teammate *lt = list_teammate_new_all_once_except(0);
    
    list_teammate_register(lt, 1);
    list_teammate_register(lt, 1);
    list_teammate_register(lt, 2);
    list_teammate_register(lt, 8);
    list_teammate_register(lt, 2);
    list_teammate_register(lt, 3);

    //printf("%s", list_teammate_to_str(lt));

    
    int *sq = malloc(4*sizeof(int));
    list_teammate_choose_squad(lt, sq);
    printf("squad : * %d %d %d\n", sq[1], sq[2], sq[3]);
    
    
    return 0;
}