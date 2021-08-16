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
    struct list_number *prev;
};

// init

struct list_number *list_number_new_element(int number, double score, int participation_number){
    struct list_number *lt = malloc(sizeof(struct list_number));

    lt->number = number;
    lt->score = score;
    lt->participation_number = participation_number;
    //lt->teammate_history = NULL;

    lt->next = NULL;
    lt->prev = NULL;

    return lt;
}


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

        lt_next->prev = lt;

        lt->number = i;
        lt->score = score_esperence;
        lt->participation_number = 1;
        lt->teammate_history = list_teammate_new_all_once_except(i);

        lt->next = lt_next;

        lt_next = lt;
    }

    lt = malloc(sizeof(struct list_number));
    
    lt_next->prev = lt;
    
    lt->next = lt_next;
    lt->prev = NULL;

    return lt;
}

// Free ...

// setters & getters
int list_number_get_number(struct list_number *lt){

    if(lt->prev==NULL){
        fprintf(stderr, "Error at list_number_get_number : Forbidden Access\n");
        exit(-1);
    }

    return lt->number;
}

double list_number_get_score(struct list_number *lt){

    if(lt->prev==NULL){
        fprintf(stderr, "Error at list_number_get_score : Forbidden Access\n Use list_number_get_by_\n");
        exit(-1);
    }

    return lt->score;
}

void list_number_update_score(struct list_number *lt, double score){

    if(lt->prev==NULL){
        fprintf(stderr, "Error at list_number_update_score : Forbidden Access\n Use list_number_get_by_\n");
        exit(-1);
    }

    double old_score = lt->score;

    lt->score = (lt->participation_number*lt->score + score)/(lt->participation_number+1);
    lt->participation_number++;

    score = lt->score;

    /*
    //Organise
    if(old_score != score){
        char incresed_score = old_score < score;

        struct list_number next_ele;

        if(incresed_score && lt->prev->prev !=NULL){

            // deattache
            lt->prev->next = lt->next;

            struct list_number *lt_i = lt->prev;
            while(lt_i->score < lt->score){
                if(lt_i->prev == NULL){
                    break;
                }
                lt_i = lt_i->prev;
            }

            lt_i->next = lt;

        }else{

        }
    }
    */
}

int list_number_get_participation_number(struct list_number *lt){

    if(lt->prev==NULL){
        fprintf(stderr, "Error at list_number_get_participation_number : Forbidden Access\n Use list_number_get_by_\n");
        exit(-1);
    }

    return lt->participation_number;
}

struct list_teammate *list_number_get_list_teammate(struct list_number *lt){
    if(lt->prev==NULL){
        fprintf(stderr, "Error at list_number_get_list_teammate : Forbidden Access\n Use list_number_get_by_\n");
        exit(-1);
    }

    return lt->teammate_history;
}

// get element
struct list_number *list_number_get_by_index(struct list_number *lt, int index){
    for(int i = 0; i<index+1; i++){
        lt = lt->next;
        if(lt == NULL){
            fprintf(stderr, "Error at list_number_get_by_index : Index out of range\n");
            exit(-1);
        }
    }

    return lt;
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

// List insert and extract
void list_number_insert_as_next(struct list_number *lt_des, struct list_number *lt_src){
    struct list_number *dest_next = lt_des->next;

    lt_des->next = lt_src;

    lt_src->prev = lt_des;
    lt_src->next = dest_next;

    if(dest_next!=NULL){
        dest_next->prev = lt_src;
    }
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

    char *out = malloc(20*100*sizeof(char));
    

    strcat(out, "list_number{\n");

    struct list_number *lt_i = lt;
    char *line = malloc(100*sizeof(char));

    while(lt_i->next != NULL){
        lt_i = lt_i->next;
        sprintf(line, "\t{number:%d, score:%lf, participation_number:%d, prev:%p, next:%p}\n", lt_i->number, lt_i->score, lt_i->participation_number, lt_i->prev, lt_i->next);
        strcat(out,line);
    }
    strcat(out,"}");
    free(line);
    return out;
}