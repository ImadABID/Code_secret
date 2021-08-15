#ifndef __LIST_NUMBER_H__
#define __LIST_NUMBER_H__

struct list_number;

// setters & getters
int list_number_get_number(struct list_number *lt);
double list_number_get_score(struct list_number *lt);
void list_number_set_score(struct list_number *lt, double score);
struct list_teammate *list_number_get_list_teammate(struct list_number *lt);


//init
struct list_number *list_number_new();

//propose_for_test
int *list_number_propose_for_test(struct list_number *lt);

//propose_for_discovery
int *list_number_propose_for_discovery(struct list_number *lt);

//Debug
char *list_number_to_str(struct list_number *lt);

#endif