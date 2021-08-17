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

// setters & getters
int number_get_number(struct number *lt){
    return lt->number;
}

double number_get_score(struct number *lt){
    return lt->score;
}

void number_update_score(struct number *nbr, double score){

    double old_score = nbr->score;

    nbr->score = (nbr->participation_number*nbr->score + score)/(nbr->participation_number+1);
    nbr->participation_number++;

    score = nbr->score;

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

int number_get_participation_number(struct number *lt){
    return lt->participation_number;
}

struct list_teammate *list_number_get_list_teammate(struct number *lt){
    return lt->teammate_history;
}

struct number *number_get_next(struct number *nbr){
    return nbr->next;
}

struct number *number_get_prev(struct number *nbr){
    return nbr->prev;
}

// List insert and extract
void number_insert_as_next(struct number *nbr, struct number *nbr_insert){

    struct number *nbr_next = nbr->next;

    nbr->next = nbr_insert;

    nbr_insert->prev = nbr;
    nbr_insert->next = nbr_next;

    if(nbr_next!=NULL){
        nbr_next->prev = nbr_insert;
    }
}

// Debug
char *number_to_str(struct number *nbr){
    char *line = malloc(100*sizeof(char));
    sprintf(line, "\t%p{number:%d, score:%lf, participation_number:%d, prev:%p, next:%p}\n", nbr, nbr->number, nbr->score, nbr->participation_number, nbr->prev, nbr->next);
    
    return line;
}