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
char teammate_path_is_visited_number(struct teammate_path_list *tpathl, int nbr);

// teammate_path_list

// Debug
void teammate_path_print(struct teammate_path *tpath);
void teammate_path_list_print(struct teammate_path_list *tpathl);

#endif