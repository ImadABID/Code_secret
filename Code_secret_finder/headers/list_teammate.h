#ifndef __LIST_TEAMMATE_H__
#define __LIST_TEAMMATE_H__

struct list_teammate;

struct list_teammate *list_teammate_new();
struct list_teammate *list_teammate_new_all_once_except(int nbr);

void list_teammate_register(struct list_teammate *lt, int nbr);

// Debug
char *list_teammate_to_str(struct list_teammate *lt);

#endif