#ifndef __NUMBER_H__
#define __NUMBER_H__

#include "../headers/list_teammate.h"
#include "../headers/list_number.h"

struct number;

//init
struct number *number_new(
    int number,
    double score,
    int participation_number,
    struct list_teammate *lt,
    struct number *next,
    struct number *prev
);

// setters & getters
int number_get_number(struct number *lt);
double number_get_score(struct number *lt);
void number_update_score(struct number *nbr, double score);
int number_get_participation_number(struct number *lt);
struct list_teammate *list_number_get_list_teammate(struct number *lt);

// List insert and extract
void list_number_insert_as_next(struct list_number *lnbr, struct number *nbr, struct number *nbr_insert);

// Debug
char *number_to_str(struct number *nbr);

#endif