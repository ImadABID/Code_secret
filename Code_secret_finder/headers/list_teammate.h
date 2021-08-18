#ifndef __LIST_TEAMMATE_H__
#define __LIST_TEAMMATE_H__

struct list_teammate;

//init
struct list_teammate *list_teammate_new();
struct list_teammate *list_teammate_new_all_once_except(int nbr);

// Free
void list_teammate_free(struct list_teammate *lt);

void list_teammate_register(struct list_teammate *lt, int nbr);
void list_teammate_choose_squad(struct list_teammate *lt, int *squad_table);

// Debug
char *list_teammate_to_str(struct list_teammate *lt);

#endif