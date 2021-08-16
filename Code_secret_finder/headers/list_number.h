#ifndef __LIST_NUMBER_H__
#define __LIST_NUMBER_H__

struct list_number;

//init
struct list_number *list_number_new_element(int number, double score, int participation_number);
struct list_number *list_number_new();

// setters & getters
int list_number_get_number(struct list_number *lt);
double list_number_get_score(struct list_number *lt);
void list_number_update_score(struct list_number *lt, double score);
int list_number_get_participation_number(struct list_number *lt);
struct list_teammate *list_number_get_list_teammate(struct list_number *lt);

// get element
struct list_number *list_number_get_head(struct list_number *lt);
struct list_number *list_number_get_by_index(struct list_number *lt, int index);
struct list_number *list_number_get_by_number(struct list_number *lt, int number);

//insert & extract
void list_number_insert_as_next(struct list_number *lt_des, struct list_number *lt_src);
void list_number_insert_as_prev(struct list_number *lt_des, struct list_number *lt_src);
struct list_number *list_number_extract(struct list_number *lt_des, struct list_number *lt_src); // returns the head of the rest

//propose_for_test
int *list_number_propose_for_test(struct list_number *lt);

//propose_for_discovery
int *list_number_propose_for_discovery(struct list_number *lt, int discovery_choice);

//Debug
char *list_number_to_str(struct list_number *lt);

#endif