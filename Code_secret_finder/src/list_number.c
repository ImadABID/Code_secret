#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../headers/list_number.h"
#include "../headers/number.h"
#include "../headers/list_teammate.h"

#define MAX_ATTEMPTS 100

struct list_number{
    struct number *first_number;
    int *proposition_hisory;
    int proposition_hisory_index;
};

//Private functions
void list_number_organise(struct list_number *lnbr, struct number *nbr);
char list_number_already_tested(struct list_number *lnbr, int *test_set);
char list_number_already_tested_no_order(struct list_number *lnbr, int *test_set);

// init
struct list_number *list_number_new(){

    double score_esperence = 1.6;

    struct list_number *lnbr = malloc(sizeof(struct list_number));
    lnbr->first_number = NULL;

    struct number *nbr;
    struct number *nbr_prev = NULL;
    
    for(int i=0; i<10; i++){

        nbr = number_new(
            i, score_esperence, 1,
            list_teammate_new_all_once_except(i),
            NULL,
            NULL
        );

        number_insert_as_next(lnbr, nbr_prev, nbr);

        nbr_prev = nbr;
    }

    lnbr->proposition_hisory = malloc(MAX_ATTEMPTS * 4 * sizeof(int));
    lnbr->proposition_hisory_index = 0;

    return lnbr;
}

// Free
void list_number_free(struct list_number *lnbr){
    if(lnbr != NULL){
        number_free(lnbr->first_number);
        free(lnbr->proposition_hisory);
        free(lnbr);
    }
}

// get element
struct number *list_number_get_by_index(struct list_number *lnbr, int index){

    struct number *nbr = lnbr->first_number;

    for(int i = 0; i<index; i++){
        nbr = number_get_next(nbr);
        if(nbr == NULL){
            fprintf(stderr, "Error at list_number_get_by_index : Index out of range\n");
            exit(-1);
        }
    }

    return nbr;
}

struct number *list_number_get_by_number(struct list_number *lnbr, int number){

    struct number *nbr = lnbr->first_number;

    while(number_get_number(nbr) != number){
        nbr = number_get_next(nbr);
        if(nbr == NULL){
            fprintf(stderr, "Error at list_number_get_by_number : unfounded number\n");
            exit(-1);
        }
    }

    return nbr;
}

//getter & setter
struct number *list_number_get_first_number(struct list_number *lnbr){
    return lnbr->first_number;
}

void list_number_set_first_number(struct list_number *lnbr, struct number *nbr){
    lnbr->first_number = nbr;
}

struct number *list_number_get_last_number(struct list_number *lnbr){
    struct number *last_number = lnbr->first_number;
    if(lnbr->first_number == NULL)
        return NULL;

    while(number_get_next(last_number) != NULL){
        last_number = number_get_next(last_number);
    }
    return last_number;
}

//propose_for_test
void list_number_propose_for_test(struct list_number *lnbr, int *test_set){

    struct number *nbr = lnbr->first_number;

    for(int i = 0; i<4; i++){

        if(nbr == NULL){
            fprintf(stderr, "Error at list_number_propose_for_test : list_number not complete\n");
            exit(-1);
        }
        
        test_set[i] = number_get_number(nbr);
        nbr = number_get_next(nbr);
    }
}

//propose_for_discover
void list_number_propose_for_discovery(struct list_number *lnbr, int discovery_choice, int *test_set){

    struct number *nbr = list_number_get_by_index(lnbr, discovery_choice);

    test_set[0] = number_get_number(nbr);

    struct list_teammate *lt = number_get_list_teammate(nbr);
    list_teammate_choose_squad(lt, test_set);
}

//propose_random
void list_number_propose_random(int *test_set){

    test_set[0] = (int) ( (double) rand() / (double) RAND_MAX * 10.0);

    test_set[1] = test_set[0];
    while (test_set[1] == test_set[0])
    {
        test_set[1] = (int) ( (double) rand() / (double) RAND_MAX * 10.0);
    }

    test_set[2] = test_set[0];
    while (test_set[2] == test_set[0] || test_set[2] == test_set[1])
    {
        test_set[2] = (int) ( (double) rand() / (double) RAND_MAX * 10.0);
    }

    test_set[3] = test_set[0];
    while (test_set[3] == test_set[0] || test_set[3] == test_set[1] || test_set[3] == test_set[2])
    {
        test_set[3] = (int) ( (double) rand() / (double) RAND_MAX * 10.0);
    }

}


//Registeration
void list_number_register_attempt(struct list_number *lnbr, int *attempt, double score){
    
    for(int i = 0; i<4; i++){

        lnbr->proposition_hisory[lnbr->proposition_hisory_index] = attempt[i];
        lnbr->proposition_hisory_index++;

        struct number *nbr = list_number_get_by_number(lnbr, attempt[i]);
        number_update_score(nbr, score);
        list_number_organise(lnbr, nbr);
    }
}

char list_number_already_tested(struct list_number *lnbr, int *test_set){
    for(int i = 0; i < lnbr->proposition_hisory_index; i+=4){
        if(
            test_set[0] == lnbr->proposition_hisory[i] &&
            test_set[1] == lnbr->proposition_hisory[i+1] &&
            test_set[2] == lnbr->proposition_hisory[i+2] &&
            test_set[3] == lnbr->proposition_hisory[i+3]
        ){
            return 1;
        }
    }

    return 0;
}

char list_number_already_tested_no_order(struct list_number *lnbr, int *test_set){

    char nbr1_exist = 0;
    char nbr2_exist = 0;
    char nbr3_exist = 0;
    char nbr4_exist = 0;

    for(int i = 0; i < lnbr->proposition_hisory_index; i+=4){
        for(int j = 0; j<4; j++){
            if(lnbr->proposition_hisory[i] == test_set[j]){
                nbr1_exist = 1;
                break;
            }
        }

        for(int j = 0; j<4; j++){
            if(lnbr->proposition_hisory[i+1] == test_set[j]){
                nbr2_exist = 1;
                break;
            }
        }

        for(int j = 0; j<4; j++){
            if(lnbr->proposition_hisory[i+2] == test_set[j]){
                nbr3_exist = 1;
                break;
            }
        }

        for(int j = 0; j<4; j++){
            if(lnbr->proposition_hisory[i+3] == test_set[j]){
                nbr4_exist = 1;
                break;
            }
        }

        if(nbr1_exist == 1 && nbr2_exist == 1 && nbr3_exist == 1 && nbr4_exist == 1){
            return 1;
        }else{
            nbr1_exist = 0;
            nbr2_exist = 0;
            nbr3_exist = 0;
            nbr4_exist = 0;
        }
    }

    return 0;
}


void list_number_organise(struct list_number *lnbr, struct number *nbr){

    struct number *next_nbr;

    next_nbr = number_get_prev(nbr);
    while(next_nbr != NULL && number_get_score(next_nbr) < number_get_score(nbr)){
        next_nbr = number_get_prev(next_nbr);
    }
    if(next_nbr != number_get_prev(nbr)){
        number_extract(lnbr, nbr);
        number_insert_as_next(lnbr, next_nbr, nbr);
    }else{
        next_nbr = number_get_next(nbr);
        while(next_nbr != NULL && number_get_score(nbr) < number_get_score(next_nbr)){
            next_nbr = number_get_next(next_nbr);
        }
        if(next_nbr != number_get_next(nbr)){
            number_extract(lnbr, nbr);
            number_insert_as_prev(lnbr, next_nbr, nbr);
        }
    }
}

// Decider
void list_number_decide_code(struct list_number *lnbr, int *test_set){
    static int discover = 0;

    if(discover){
        list_number_propose_for_discovery(lnbr, 0, test_set);
        discover = 0;
    }else{
        list_number_propose_for_test(lnbr, test_set);
        discover = 1;
    }

    while(list_number_already_tested_no_order(lnbr, test_set)){
        list_number_propose_random(test_set);
    }

}

// Debug
void list_number_to_str(struct list_number *lnbr, char *str){
    /*
    list_number{
        {number:1, score:2.2, participation_number:4}
        {number:2, score:1.4, participation_number:3}
    }
    */

    char *line = malloc(400*sizeof(char));
    
    strcpy(str, "list_number{\n");

    struct number *nbr = lnbr->first_number;

    while(nbr != NULL){
        number_to_str(nbr, line);
        strcat(str,line);
        nbr = number_get_next(nbr);
    }
    strcat(str,"}");
    free(line);
}

void list_number_to_str_in_1_line(struct list_number *lnbr, char *str){
    struct number *nbr = lnbr->first_number;
    strcpy(str, "\t");
    char *slice = malloc(10*sizeof(char));
    while(nbr != NULL){
        sprintf(slice, "%d:%d:%lf ", number_get_number(nbr), number_get_participation_number(nbr), number_get_score(nbr));
        strcat(str,slice);
        nbr = number_get_next(nbr);
    }
}