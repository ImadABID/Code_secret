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

void list_number_update_score(struct list_number *lt, double score){
    if(lt->next==NULL){
        fprintf(stderr, "Error at list_number_get_score : list_number empty");
        exit(-1);
    }

    lt->next->score = (lt->next->participation_number*lt->next->score + score)/(lt->next->participation_number+1);
    lt->next->participation_number++;
}

int list_number_get_participation_number(struct list_number *lt){

    if(lt->next==NULL){
        fprintf(stderr, "Error at list_number_get_score : list_number empty");
        exit(-1);
    }

    return lt->next->participation_number;
}

struct list_teammate *list_number_get_list_teammate(struct list_number *lt){
    if(lt->next==NULL){
        fprintf(stderr, "Error at list_number_get_list_teammate : list_number empty");
        exit(-1);
    }

    return lt->next->teammate_history;
}

struct list_number *list_number_get_by_index(struct list_number *lt, int index){
    struct list_number *lt_pre;
    for(int i = 0; i<index+1; i++){
        lt_pre = lt;
        lt = lt->next;
        if(lt == NULL){
            fprintf(stderr, "Error at list_number_get_by_index : Index out of range\n");
            exit(-1);
        }
    }

    return lt_pre;
}

struct list_number *list_number_get_by_number(struct list_number *lt, int number){
    struct list_number *lt_pre = lt;
    lt = lt->next;
    while(lt->number != number){
        lt_pre = lt;
        lt = lt->next;
        if(lt == NULL){
            fprintf(stderr, "Error at list_number_get_by_number : unfounded number\n");
            exit(-1);
        }
    }

    return lt_pre;
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
int *list_number_propose_for_discovery(struct list_number *lnbr, int discovery_choice){

    int *test_set = malloc(4*sizeof(int));

    lnbr = list_number_get_by_index(lnbr, discovery_choice);

    test_set[0] = list_number_get_number(lnbr);
    struct list_teammate *lt = list_number_get_list_teammate(lnbr);

    list_teammate_choose_squad(lt, test_set);

    return test_set;
}

/*
//Registeration
void list_number_register_attempt(struct list_number *lt, int *attempt, int score){
    
    for(int i = 0; i<4; i++){
        list_number_update_score(list_number_get_by_number(lt, attempt[i]));
    }
}
*/

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