#include<stdio.h>
#include<stdlib.h>


#include "../headers/teammate_graph.h"


// Init
int **teammate_graph_init(){

    int **tr = (int **)malloc(9*sizeof(int *));

    for(int i = 1; i < 10; i++){
    
        tr[i-1] = (int *) malloc(i * sizeof(int));

        for(int j = 0; j < i; j++){
            tr[i-1][j] = 1;
        }
    }

    return tr;
}

// Free
void teammate_graph_free(int **tr){
    for(int i = 0; i < 9; i++){
        free(tr[i]);
    }
    free(tr);
}

// Basic Functions
int teammate_graph_get_teammate_nbr(int **tr, int i, int j){
    if(i==j){
        fprintf(stderr, "Error at teammate_graph_get_teammate_nbr: teammate is not defined between the same number.\n");
        exit(-1);
    }
    if(i<j){
        return teammate_graph_get_teammate_nbr(tr, j, i);
    }

    return tr[i-1][j];
}

void teammate_graph_increment_teammate_nbr(int **tr, int i, int j){
    if(i==j){
        fprintf(stderr, "Error at teammate_graph_increment_teammate_nbr: teammate is not defined between the same number.\n");
        exit(-1);
    }
    if(i<j){
        return teammate_graph_increment_teammate_nbr(tr, j, i);
    }

    tr[i-1][j]++;
}

// Debug
void teammate_graph_print(int **tr){
    for(int i = 1; i < 10; i++){
        for(int j = 0; j < i; j++){
            printf("(%d, %d)=%d\t", i, j, teammate_graph_get_teammate_nbr(tr, i, j));
        }
        printf("\n");
    }
}