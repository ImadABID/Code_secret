#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../headers/list_number.h"
#include "../headers/number.h"
#include "../headers/list_teammate.h"

struct list_number{
    struct number *first_number;
};

// init
struct list_number *list_number_new(){

    double score_esperence = 1.6;

    struct list_number *lnbr;

    struct number *nbr;
    struct number *nbr_prev = number_new(
        0, score_esperence, 1,
        list_teammate_new_all_once_except(0),
        NULL,
        NULL
    );

    lnbr->first_number = nbr_prev;
    
    for(int i=1; i<10; i++){

        nbr = number_new(
            i, score_esperence, 1,
            list_teammate_new_all_once_except(i),
            NULL,
            NULL
        );

        number_insert_as_next(nbr_prev, nbr);

        nbr_prev = nbr;
    }

    return lnbr;
}

// Free ...

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

/*
//Registeration
void list_number_register_attempt(struct list_number *lt, int *attempt, int score){
    
    for(int i = 0; i<4; i++){
        list_number_update_score(list_number_get_by_number(lt, attempt[i]));
    }
}
*/

// Debug
void list_number_to_str(struct list_number *lnbr, char *str){
    /*
    list_number{
        {number:1, score:2.2, participation_number:4}
        {number:2, score:1.4, participation_number:3}
    }
    */

    char *line = malloc(200*sizeof(char));

    strcat(str, "list_number{\n");

    struct number *nbr = lnbr->first_number;

    while(nbr != NULL){
        number_to_str(nbr, line);
        strcat(str,line);
        nbr = number_get_next(nbr);
    }
    strcat(str,"}");
    free(line);
}