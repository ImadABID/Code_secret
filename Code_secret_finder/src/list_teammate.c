#include<stdio.h>
#include<stdlib.h>

#include "headers/list_teammate.h"

struct list_teammate{
    int number;
    int teammate_occasion_number;
    struct list_teammate *next;
};

char list_teammate_empty(struct list_teammate *lt){
    return lt->next == NULL;
}

struct list_teammate *list_teammate_new(){
    struct list_teammate *lt_new = malloc(sizeof(struct list_teammate));
    lt_new->next = NULL;
    return lt_new;
}

// Free ...

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

void list_teammate_organise(struct list_teammate *previous_teammate){
    
    if(list_teammate_empty(previous_teammate)){
        fprintf(stderr, "list_teammate_organise : No teammate to organise\n");
    }

    char organiased = 0;

    struct list_teammate *lt_to_organise = previous_teammate->next;

    struct list_teammate *lt_i_pre;
    struct list_teammate *lt_i = previous_teammate;

    while(lt_i->next!=NULL){
        lt_i_pre = lt_i;
        lt_i = lt_i->next;

        if(lt_to_organise->number <= lt_i->number){
            previous_teammate->next = previous_teammate->next->next;
            lt_i_pre->next = lt_to_organise;
            lt_to_organise->next = lt_i;

            organiased = 1;
        }
    }

    if(!organiased){
        previous_teammate->next = previous_teammate->next->next;
        lt_i->next = lt_to_organise;
        lt_to_organise->next = NULL;
    }
}