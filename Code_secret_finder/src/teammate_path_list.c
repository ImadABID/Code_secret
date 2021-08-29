#include<stdio.h>
#include<stdlib.h>

#include "../headers/teammate_path_list.h"
#include "../headers/teammate_graph.h"

struct teammate_path{
    int number;
    int path_size;
    int *path;
    int distance;

    struct teammate_path *next;
};

struct teammate_path_list{
    struct teammate_path *first_path;
    int origin;
    int confirmed_order;
};

struct teammate_path *teammate_path_init(int nbr, int dist, struct teammate_path *next){

    struct teammate_path *tpath = malloc(sizeof(struct teammate_path));

    tpath->number = nbr;
    tpath->next = next;

    tpath->path_size = 0;
    tpath->path = malloc(10*sizeof(int));
    tpath->distance = dist;

    return tpath;
}

void teammate_path_free(struct teammate_path *tpath){
    teammate_path_free(tpath->next);
    free(tpath->path);
    free(tpath);
}

struct teammate_path_list *teammate_path_list_init(int origin){

    struct teammate_path_list *tpathl = malloc(sizeof(struct teammate_path_list));

    struct teammate_path *p = NULL;
    struct teammate_path *c;

    for(int i = 0; i < 10 ; i++){
        if(i != origin){
            c = teammate_path_init(i, -1, p);
            p = c;
        }
    }

    c = teammate_path_init(origin, 0, p);
    int path[] = {origin};
    teammate_path_copy_path(c, path, 1);

    tpathl->first_path = c;
    tpathl->confirmed_order = 1;
    tpathl->origin = origin;

    return tpathl;
}

void teammate_path_list_free(struct teammate_path_list *tpathl){
    teammate_path_free(tpathl->first_path);
    free(tpathl);
}

// teammate_path

void teammate_path_copy_path(struct teammate_path *tpath, int *path, int path_size){
    for(int i = 0; i < path_size; i++){
        tpath->path[i] = path[i];
    }

    tpath->path_size = path_size;
}

char teammate_path_is_visited_number(struct teammate_path_list *tpathl, int nbr){
    
    struct teammate_path *tpath = tpathl->first_path;
    
    for(int i = 0; i < tpathl->confirmed_order; i++){
        if(tpath->number == nbr)
            return 1;
    }

    return 0;
}

void teammate_path_extract(struct teammate_path_list *tpathl, struct teammate_path *ptpath, struct teammate_path *tpath){
    if(ptpath == NULL){
        //printf("\tteammate_path_extract : prev = NULL\n");
        tpathl->first_path = tpath->next;
    }else{
        //printf("\tteammate_path_extract : prev = %d\n", ptpath->number);
        ptpath->next = tpath->next;
    }
}

void teammate_path_insert_as_next(struct teammate_path_list *tpathl, struct teammate_path *ptpath, struct teammate_path *tpath){
    if(ptpath == NULL){
        //printf("\tteammate_path_insert_as_next : prev = NULL\n");
        tpath->next = tpathl->first_path;
        tpathl->first_path = tpath;
    }else{
        //printf("\tteammate_path_insert_as_next : prev = %d\n", ptpath->number);
        tpath->next = ptpath->next;
        ptpath->next = tpath;
    }
}

void teammate_path_organise(struct teammate_path_list *tpathl, struct teammate_path *to_organise){
    
    //printf("--- Organising %d ---\n", to_organise->number);

    struct teammate_path *path = tpathl->first_path;
    struct teammate_path *prev_path = NULL;

    struct teammate_path *prev_extract = NULL;
    struct teammate_path *prev_insert = NULL;

    char extracted_in_this_iter = 0;
    char inserted = 0;

    while(path != NULL){

        if(path == to_organise){
            prev_extract = prev_path;
            extracted_in_this_iter = 1;
        }

        if(!inserted && (to_organise->distance < path->distance || path->distance == -1 )){
            prev_insert = prev_path;
            inserted = 1;
        }

        if(extracted_in_this_iter){
            extracted_in_this_iter = 0;
        }else{
            prev_path = path;
        }

        path = path->next;
    }

    //printf("\nExtracting %d\n", to_organise->number);
    teammate_path_extract(tpathl, prev_extract, to_organise);
    //teammate_path_list_print(tpathl);

    //printf("\nInserting %d\n", to_organise->number);
    teammate_path_insert_as_next(tpathl, prev_insert, to_organise);
    //teammate_path_list_print(tpathl);
}

// teammate_path_list

void teammate_path_list_get_rare_squad(struct teammate_path_list *tpathl){
    // To implemente
}

void teammate_path_next_visit(int **tr, struct teammate_path_list *tpathl){

    struct teammate_path *to_visit = tpathl->first_path;
    struct teammate_path *origin_path = NULL;

    int i = 0;
    int new_dist;

    while(to_visit != NULL){

        if(origin_path != NULL){
            new_dist =
                origin_path->distance +
                teammate_graph_get_teammate_nbr(tr, origin_path->number, to_visit->number)
            ;

            if(to_visit->distance == -1 || to_visit->distance > new_dist){
                to_visit->distance = new_dist;
                //update path
                teammate_path_organise(tpathl, to_visit);
                //break;
            }
        }

        if(i == tpathl->confirmed_order - 1){
            origin_path = to_visit;
        }

        i++;
        to_visit = to_visit->next;
    }
    
    tpathl->confirmed_order++;
}

// Debug
void teammate_path_print(struct teammate_path *tpath){
    printf("\t number : %d distance : %d\tpath : ", tpath->number, tpath->distance);
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
    while(tpath != NULL && i<11){

        if(i < tpathl->confirmed_order){
            printf("%d : *", i);
        }else{
            printf("%d : ?", i);
        }

        teammate_path_print(tpath);

        tpath = tpath->next;
        i++;
    }
}