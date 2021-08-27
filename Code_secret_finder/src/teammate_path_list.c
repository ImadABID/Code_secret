#include<stdio.h>
#include<stdlib.h>

#include "../headers/teammate_path_list.h"

struct teammate_path{
    int number;
    int path_size;
    int *path;

    struct teammate_path *next;
};

struct teammate_path_list{
    struct teammate_path *first_path;
    int confirmed_order;
};

struct teammate_path *teammate_path_init(int nbr, struct teammate_path *next){

    struct teammate_path *tpath = malloc(sizeof(struct teammate_path));

    tpath->number = nbr;
    tpath->next = next;

    tpath->path_size = 0;
    tpath->path = malloc(10*sizeof(int));

    return tpath;
}

void teammate_path_free(struct teammate_path *tpath){
    teammate_path_free(tpath->next);
    free(tpath->path);
    free(tpath);
}

struct teammate_path_list *teammate_path_list_init(){

    struct teammate_path_list *tpathl = malloc(sizeof(struct teammate_path_list));

    struct teammate_path *p = NULL;
    struct teammate_path *c;

    for(int i = 0; i < 10 ; i++){
        c = teammate_path_init(i, p);
        p = c;
    }

    tpathl->first_path = c;

    tpathl->confirmed_order = 0;

    return tpathl;
}

void teammate_path_list_free(struct teammate_path_list *tpathl){
    teammate_path_free(tpathl->first_path);
    free(tpathl);
}

// Debug
void teammate_path_print(struct teammate_path *tpath){
    printf("\t number : %d\tpath : ", tpath->number);
    if( tpath->path_size == 0 ){
        printf("-");
    }else{
        for(int i = 0; i < tpath->path_size; i++){
            printf("%d", tpath->path[i]);
        }
    }
    printf("\n");
}

void teammate_path_list_print(struct teammate_path_list *tpathl){
    struct teammate_path *tpath = tpathl->first_path;

    int i = 0;
    while(tpath != NULL){

        if(i < tpathl->confirmed_order){
            printf("*");
        }else{
            printf("?");
        }

        teammate_path_print(tpath);

        tpath = tpath->next;
        i++;
    }
}