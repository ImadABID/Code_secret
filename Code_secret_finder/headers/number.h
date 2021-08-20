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

//free
void number_free(struct number *nbr);

// setters & getters
int number_get_number(struct number *lt);
double number_get_score(struct number *lt);
void number_update_score(struct number *nbr, double score);
int number_get_participation_number(struct number *lt);
struct list_teammate *number_get_list_teammate(struct number *lt);
struct number *number_get_next(struct number *nbr);
struct number *number_get_prev(struct number *nbr);

// List insert and extract
void number_insert_as_next(struct number *nbr, struct number *nbr_insert);

// Debug
void number_to_str(struct number *nbr, char *str);

#endif