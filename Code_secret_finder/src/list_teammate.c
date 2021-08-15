#include<stdlib.h>

#include "headers/list_int.h"

struct list_teammate{
    int number;
    int teammate_occasion_number;
    struct list_teammate *next;
};

char list_teammate_empty(struct list_teammate *lt){
    return lt->next == NULL;
}

void list_teammate_register(struct list_teammate *lt, int nbr){
    char registered = 0;
    struct list_teammate *lt_pre_i;
    struct list_teammate *lt_i = lt;
    while(lt_i->next != NULL){
        lt_pre_i = lt_i;
        lt_i = lt_i->next;
        if(lt_i->number == nbr){
            lt_i->teammate_occasion_number++;
            list_teammate_organise(lt_pre_i);
            registered = 1;
            break;
        }
    }
    if(!registered){
        struct list_teammate *teammate = malloc(sizeof(struct list_teammate));
        teammate->number = nbr;
        teammate->teammate_occasion_number = 0;
        teammate->next = lt->next;
        lt->next = teammate;
    }
}

void list_teammate_organise(){

}