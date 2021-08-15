#include<stdlib.h>

#include "headers/list_int.h"

struct list_teammate{
    int number;
    int teammate_occasion_number;
    struct list_teammate *next;
};

char list_teammate_empty(struct list_teammate *lt){
    return lt->next == NULL;
}

