#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../headers/list_teammate.h"

// Private functions header
void list_teammate_organise(struct list_teammate *previous_teammate);
char list_teammate_empty(struct list_teammate *lt);

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

struct list_teammate *list_teammate_new_all_once_except(int nbr){
    struct list_teammate *lt = list_teammate_new();
    for(int i=0; i<10; i++){
        if(i!=nbr)
            list_teammate_register(lt, i);
    }
    return lt;
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
        teammate->teammate_occasion_number = 1;
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

    previous_teammate->next = lt_to_organise->next;

    struct list_teammate *lt_i_pre;
    struct list_teammate *lt_i = previous_teammate;

    while(lt_i->next!=NULL){
        lt_i_pre = lt_i;
        lt_i = lt_i->next;

        if(lt_to_organise->teammate_occasion_number <= lt_i->teammate_occasion_number){

            lt_i_pre->next = lt_to_organise;
            lt_to_organise->next = lt_i;

            organiased = 1;
            break;
        }
    }

    if(!organiased){
        lt_i->next = lt_to_organise;
        lt_to_organise->next = NULL;
    }
}

// Debug
char *list_teammate_to_str(struct list_teammate *lt){
    /*
    list_teammate{
        {number:1, teammate_occasion_number:2}
        {number:2, teammate_occasion_number:4}
    }
    */

    char *out = malloc(10*50*sizeof(char));
    

    strcat(out, "list_teammate{\n");

    struct list_teammate *lt_i = lt;
    char *line = malloc(50*sizeof(char));

    while(lt_i->next != NULL){
        lt_i = lt_i->next;
        sprintf(line, "\t{number:%d, teammate_occasion_number:%d}\n", lt_i->number, lt_i->teammate_occasion_number);
        strcat(out,line);
    }
    strcat(out,"}");
    free(line);
    return out;
}