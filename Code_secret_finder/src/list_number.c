#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../headers/list_number.h"
#include "../headers/list_teammate.h"


struct list_number{
    int number;
    int score; // not normalize
    int participation_number;
    struct list_teammate *teammate_history;

    struct list_number *next;
};

struct list_number *list_number_new(){

    int init_score = 1; // To verify

    struct list_number *lt;
    struct list_number *lt_next = malloc(sizeof(struct list_number));

    lt_next->number = 9;
    lt_next->score = init_score;
    lt_next->participation_number = 1;
    lt_next->teammate_history = list_teammate_new_all_once_except(9);

    lt_next->next = NULL;

    for(int i=8; i>=0; i--){
        lt = malloc(sizeof(struct list_number));

        lt->number = i;
        lt->score = init_score;
        lt->participation_number = 1;
        lt->teammate_history = list_teammate_new_all_once_except(i);

        lt->next = lt_next;

        lt_next = lt;
    }

    lt = malloc(sizeof(struct list_number));
    lt->next = lt_next;

    return lt;
}

// Free ...

// Debug
char *list_number_to_str(struct list_number *lt){
    /*
    list_number{
        {number:1, score:2, participation_number:3}
        {number:2, score:3, participation_number:3}
    }
    */

    char *out = malloc(10*50*sizeof(char));
    

    strcat(out, "list_number{\n");

    struct list_number *lt_i = lt;
    char *line = malloc(50*sizeof(char));

    while(lt_i->next != NULL){
        lt_i = lt_i->next;
        sprintf(line, "\t{number:%d, score:%d, participation_number:%d}\n", lt_i->number, lt_i->score, lt_i->participation_number);
        strcat(out,line);
    }
    strcat(out,"}");
    free(line);
    return out;
}