#ifndef __LIST_TEAMMATE_H__
#define __LIST_TEAMMATE_H__

struct list_teammate;

struct list_teammate *list_teammate_new();

void list_teammate_register(struct list_teammate *lt, int nbr);

#endif