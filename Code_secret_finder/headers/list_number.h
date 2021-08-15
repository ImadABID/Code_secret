#ifndef __LIST_NUMBER_H__
#define __LIST_NUMBER_H__

struct list_number;

//init
struct list_number *list_number_new();

//propose_for_test
int *list_number_propose_for_test(struct list_number *lt);

//propose_for_discovery
int *list_number_propose_for_discovery(struct list_number *lt);

//Debug
char *list_number_to_str(struct list_number *lt);

#endif