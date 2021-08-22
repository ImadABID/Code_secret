#ifndef __LIST_NUMBER_H__
#define __LIST_NUMBER_H__

struct list_number;

//init
struct list_number *list_number_new();

// Free
void list_number_free(struct list_number *lnbr);

// get element
struct number *list_number_get_by_index(struct list_number *lnbr, int index);
struct number *list_number_get_by_number(struct list_number *lnbr, int number);

//getter & setter
struct number *list_number_get_first_number(struct list_number *lnbr);
void list_number_set_first_number(struct list_number *lnbr, struct number *nbr);
struct number *list_number_get_last_number(struct list_number *lnbr);
struct number *list_number_get_least_tested(struct list_number *lnbr);

//propose
void list_number_propose_for_test(struct list_number *lnbr, int *test_set);
void list_number_propose_for_discovery(struct list_number *lnbr, int *test_set);
void list_number_propose_random(int *test_set);

//Registeration
void list_number_register_attempt(struct list_number *lnbr, int *attempt, double score);


// Decider
void list_number_decide_code(struct list_number *lnbr, int *test_set);

//Debug
void list_number_to_str(struct list_number *lnbr, char *str);
void list_number_to_str_in_1_line(struct list_number *lnbr, char *str);

#endif