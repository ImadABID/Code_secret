#ifndef __TEAMMATE_PATH_LIST__H__
#define __TEAMMATE_PATH_LIST__H__

struct teammate_path;
struct teammate_path_list;

struct teammate_path *teammate_path_init(int nbr, int dist, struct teammate_path *next);
void teammate_path_free(struct teammate_path *tpath);

struct teammate_path_list *teammate_path_list_init(int origin);
void teammate_path_list_free(struct teammate_path_list *tpathl);

// teammate_path
void teammate_path_copy_path(struct teammate_path *tpath, int *path, int path_size);
void teammate_path_extract(struct teammate_path_list *tpathl, struct teammate_path *ptpath, struct teammate_path *tpath);
void teammate_path_insert_as_next(struct teammate_path_list *tpathl, struct teammate_path *ptpath, struct teammate_path *tpath);

void teammate_path_organise(struct teammate_path_list *tpathl, struct teammate_path *to_organise);

char teammate_path_is_visited_number(struct teammate_path_list *tpathl, int nbr);

// teammate_path_list

void teammate_path_next_visit(int **tr, struct teammate_path_list *tpathl);


// Debug
void teammate_path_print(struct teammate_path *tpath);
void teammate_path_list_print(struct teammate_path_list *tpathl);

#endif