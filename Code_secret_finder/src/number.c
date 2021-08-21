#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../headers/number.h"
#include "../headers/list_number.h"
#include "../headers/list_teammate.h"

struct number{
    int number;
    double score;
    int participation_number;
    struct list_teammate *teammate_history;

    struct number *next;
    struct number *prev;
};

//init
struct number *number_new(
    int number,
    double score,
    int participation_number,
    struct list_teammate *lt,
    struct number *next,
    struct number *prev
){
    struct number *nbr = malloc(sizeof(struct number));

    nbr->number = number;
    nbr->score = score;
    nbr->participation_number = participation_number;
    nbr->teammate_history = lt;

    nbr->next = next;
    nbr->prev = prev;

    return nbr;
}

//free
void number_free(struct number *nbr){
    if(nbr != NULL){
        if(nbr->prev!=NULL){
            number_free(nbr->prev);
        }else{
            if(nbr->next != NULL){
                nbr->next->prev = NULL;
                number_free(nbr->next);
            }
            list_teammate_free(nbr->teammate_history);
            free(nbr);
        }
    }
}

// setters & getters
int number_get_number(struct number *lt){
    return lt->number;
}

double number_get_score(struct number *lt){
    return lt->score;
}

void number_update_score(struct number *nbr, double score){

    nbr->score = (nbr->participation_number*nbr->score + score)/(nbr->participation_number+1);
    nbr->participation_number++;

}

int number_get_participation_number(struct number *lt){
    return lt->participation_number;
}

struct list_teammate *number_get_list_teammate(struct number *lt){
    return lt->teammate_history;
}

struct number *number_get_next(struct number *nbr){
    return nbr->next;
}

struct number *number_get_prev(struct number *nbr){
    return nbr->prev;
}

// List insert and extract
void number_insert_as_next(struct list_number *lnbr, struct number *nbr, struct number *nbr_insert){

    struct number *next_nbr = NULL;

    nbr_insert->prev = nbr;
    if(nbr == NULL){
        next_nbr = list_number_get_first_number(lnbr);
        list_number_set_first_number(lnbr, nbr_insert);
    }else{
        next_nbr = nbr->next;
        nbr->next = nbr_insert;
    }

    nbr_insert->next = next_nbr;
    if(next_nbr != NULL){
        next_nbr->prev = nbr_insert;
    }

}

void number_insert_as_prev(struct list_number *lnbr, struct number *nbr, struct number *nbr_insert){

    struct number *prev_nbr;

    nbr_insert->next = nbr;
    if(nbr == NULL){
        prev_nbr = list_number_get_last_number(lnbr);
    }else{
        prev_nbr = nbr->prev;
        nbr->prev = nbr_insert;
    }

    nbr_insert->prev = prev_nbr;
    if(prev_nbr != NULL){
        prev_nbr->next = nbr_insert;
    }
}

void number_extract(struct list_number *lnbr, struct number *nbr){
    if(nbr == list_number_get_by_index(lnbr, 0)){
        list_number_set_first_number(lnbr, nbr->next);
        nbr->next->prev = NULL;
    }else{
        nbr->prev->next = nbr->next;
        if(nbr->next != NULL)
            nbr->next->prev = nbr->prev;
    }
}

// Debug
void number_to_str(struct number *nbr, char *str){
    sprintf(str, "\t%p{number:%d, score:%lf, participation_number:%d, prev:%p, next:%p}\n", nbr, nbr->number, nbr->score, nbr->participation_number, nbr->prev, nbr->next);
}