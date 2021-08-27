#ifndef __TEAMMATE_GRAPH_H__
#define __TEAMMATE_GRAPH_H__

// Init
int **teammate_graph_init();

// Free
void teammate_graph_free(int **tr);

// Basic Functions
int teammate_graph_get_teammate_nbr(int **tr, int i, int j);
void teammate_graph_increment_teammate_nbr(int **tr, int i, int j);

// Debug
void teammate_graph_print(int **tr);

#endif