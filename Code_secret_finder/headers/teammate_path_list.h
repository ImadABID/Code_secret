#ifndef __TEAMMATE_PATH_LIST__H__
#define __TEAMMATE_PATH_LIST__H__

struct teammate_path;
struct teammate_path_list;

struct teammate_path *teammate_path_init(int nbr, struct teammate_path *next);
void teammate_path_free(struct teammate_path *tpath);

struct teammate_path_list *teammate_path_list_init();
void teammate_path_list_free(struct teammate_path_list *tpathl);

// Debug
void teammate_path_print(struct teammate_path *tpath);
void teammate_path_list_print(struct teammate_path_list *tpathl);

#endif