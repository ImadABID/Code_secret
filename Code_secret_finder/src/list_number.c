#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../headers/list_number.h"
#include "../headers/list_teammate.h"


struct list_number{
    int number;
    double score;
    int participation_number;
    struct list_teammate *teammate_history;

    struct list_number *next;
};

struct list_number *list_number_new(){

    double score_esperence = 1.6;

    struct list_number *lt;
    struct list_number *lt_next = malloc(sizeof(struct list_number));

    lt_next->number = 9;
    lt_next->score = score_esperence;
    lt_next->participation_number = 1;
    lt_next->teammate_history = list_teammate_new_all_once_except(9);

    lt_next->next = NULL;

    for(int i=8; i>=0; i--){
        lt = malloc(sizeof(struct list_number));

        lt->number = i;
        lt->score = score_esperence;
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

// setters & getters
int list_number_get_number(struct list_number *lt){

    if(lt->next==NULL){
        fprintf(stderr, "Error at list_number_get_number : list_number empty");
        exit(-1);
    }

    return lt->next->number;
}

double list_number_get_score(struct list_number *lt){

    if(lt->next==NULL){
        fprintf(stderr, "Error at list_number_get_score : list_number empty");
        exit(-1);
    }

    return lt->next->score;
}

void list_number_set_score(struct list_number *lt, double score){
    if(lt->next==NULL){
        fprintf(stderr, "Error at list_number_get_score : list_number empty");
        exit(-1);
    }

    lt->next->score = score;
}

struct list_teammate *list_number_get_list_teammate(struct list_number *lt){
    if(lt->next==NULL){
        fprintf(stderr, "Error at list_number_get_list_teammate : list_number empty");
        exit(-1);
    }

    return lt->next->teammate_history;
}

//propose_for_test
int *list_number_propose_for_test(struct list_number *lt){
    int *test_set = malloc(4*sizeof(int));

    struct list_number *lt_i = lt->next;

    for(int i = 0; i<4; i++){
        if(lt_i == NULL){
            fprintf(stderr, "Error at list_number_propose_for_test : list_number not complete\n");
            exit(-1);
        }
        test_set[i] = lt_i->number;
        lt_i = lt_i->next;
    }

    return test_set;
}

//propose_for_discover

// Debug
char *list_number_to_str(struct list_number *lt){
    /*
    list_number{
        {number:1, score:2.2, participation_number:4}
        {number:2, score:1.4, participation_number:3}
    }
    */

    char *out = malloc(10*100*sizeof(char));
    

    strcat(out, "list_number{\n");

    struct list_number *lt_i = lt;
    char *line = malloc(50*sizeof(char));

    while(lt_i->next != NULL){
        lt_i = lt_i->next;
        sprintf(line, "\t{number:%d, score:%lf, participation_number:%d}\n", lt_i->number, lt_i->score, lt_i->participation_number);
        strcat(out,line);
    }
    strcat(out,"}");
    free(line);
    return out;
}