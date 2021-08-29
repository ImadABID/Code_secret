#include<stdio.h>
#include<stdlib.h>

#include "../headers/teammate_path_list.h"
#include "../headers/teammate_graph.h"

int main(){

    int **tr = teammate_graph_init();

    teammate_graph_increment_teammate_nbr(tr, 2, 9);
    teammate_graph_increment_teammate_nbr(tr, 2, 6);
    teammate_graph_increment_teammate_nbr(tr, 2, 6);
    teammate_graph_increment_teammate_nbr(tr, 2, 6);
    teammate_graph_increment_teammate_nbr(tr, 2, 3);
    teammate_graph_increment_teammate_nbr(tr, 2, 3);
    teammate_graph_increment_teammate_nbr(tr, 2, 3);
    teammate_graph_increment_teammate_nbr(tr, 2, 3);
    teammate_graph_increment_teammate_nbr(tr, 2, 3);

    struct teammate_path_list *tpathl = teammate_path_list_init(2);
    teammate_path_list_print(tpathl);

    while(teammate_path_list_get_confirmed_order(tpathl)<10){
        printf("\n");
        teammate_path_next_visit(tr, tpathl);
        teammate_path_list_print(tpathl);
    }

    return 0;
}