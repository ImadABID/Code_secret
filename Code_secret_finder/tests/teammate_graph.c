#include<stdio.h>
#include<stdlib.h>

#include "../headers/teammate_graph.h"

int main(){
    
    int **tr = teammate_graph_init();
    teammate_graph_print(tr);
    
    teammate_graph_increment_teammate_nbr(tr, 5, 3);
    teammate_graph_print(tr);
    
    teammate_graph_free(tr);
    return 0;
}