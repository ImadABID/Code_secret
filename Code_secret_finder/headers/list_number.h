#ifndef __LIST_NUMBER_H__
#define __LIST_NUMBER_H__

struct list_number;

//init
struct list_number *list_number_new();

// get element
struct number *list_number_get_by_index(struct list_number *lnbr, int index);
struct number *list_number_get_by_number(struct list_number *lnbr, int number);

//propose_for_test
void list_number_propose_for_test(struct list_number *lnbr, int *test_set);

//propose_for_discovery
void list_number_propose_for_discovery(struct list_number *lnbr, int discovery_choice, int *test_set);

//Debug
void list_number_to_str(struct list_number *lnbr, char *str);

#endif