#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "../headers/list_teammate.h"

// Private functions header
void teammate_increment_occasion_number(struct list_teammate *lt, struct teammate *previous_teammate);

struct teammate{
    int number;
    int teammate_occasion_number;
    struct teammate *next;
};

struct list_teammate{
    struct teammate *next;
};

struct teammate *teammate_new(int number, struct teammate *next){
    struct teammate *tm = malloc(sizeof(struct teammate));
    tm->number = number;
    tm->teammate_occasion_number = 1;
    tm->next = next;
    return tm;
}

struct list_teammate *list_teammate_new_all_once_except(int nbr){
    struct list_teammate *lt = malloc(sizeof(struct list_teammate));
    lt->next = NULL;
    for(int i=0; i<10; i++){
        if(i!=nbr)
            list_teammate_register(lt, i);
    }
    return lt;
}

// Free

void teammate_free(struct teammate *tm){
    if(tm != NULL){
        teammate_free(tm->next);
        free(tm);
    }
}

void list_teammate_free(struct list_teammate *lt){
    if(lt != NULL){
        teammate_free(lt->next);
        free(lt);
    }
}

void list_teammate_register(struct list_teammate *lt, int nbr){

    struct teammate *tm_prev = NULL;
    struct teammate *tm = lt->next;
    while(tm !=NULL && tm->number != nbr){
        tm_prev = tm;
        tm = tm->next;
    }

    if(tm == NULL){
        lt->next = teammate_new(nbr, lt->next);
    }else{
        teammate_increment_occasion_number(lt, tm_prev);
    }
}

void teammate_increment_occasion_number(struct list_teammate *lt, struct teammate *previous_teammate){

    struct teammate *tm_to_organise;
    if(previous_teammate == NULL){
        tm_to_organise = lt->next;
    }else{
        tm_to_organise = previous_teammate->next;
    }
    if(tm_to_organise == NULL){
        fprintf(stderr, "Error at teammate_increment_occasion_number : No next element\n");
        exit(-1);
    }

    tm_to_organise->teammate_occasion_number ++;

    if(previous_teammate == NULL){
        lt->next = tm_to_organise->next;
    }else{
        previous_teammate->next = tm_to_organise->next;
    }

    while(previous_teammate->next != NULL && tm_to_organise->teammate_occasion_number <= previous_teammate->next->teammate_occasion_number){
        previous_teammate = previous_teammate->next;
    }

    tm_to_organise->next = previous_teammate->next;
    previous_teammate->next = tm_to_organise;

}

void list_teammate_choose_squad(struct list_teammate *lt, int *squad_table){
    struct teammate * tm = lt->next;
    for(int i = 1; i<4; i++){
        if(tm==NULL){
            fprintf(stderr, "Error at list_teammate_choose_squad : list_teammate uncompleted\n");
            exit(-1);
        }
        squad_table[i] = tm->number;
        tm = tm->next;
    }
}

// Debug

void teammate_to_str(struct teammate *tm, char *str){
    sprintf(str, "\t{number:%d, teammate_occasion_number:%d}\n", tm->number, tm->teammate_occasion_number);
}

void list_teammate_to_str(struct list_teammate *lt, char *str){
    /*
    list_teammate{
        {number:1, teammate_occasion_number:2}
        {number:2, teammate_occasion_number:4}
    }
    */

    strcat(str, "list_teammate{\n");

    struct teammate *tm = lt->next;
    char *line = malloc(50*sizeof(char));

    while(tm != NULL){
        teammate_to_str(tm, line);
        strcat(str,line);
        tm = tm->next;
    }
    strcat(str,"}");
    free(line);
}