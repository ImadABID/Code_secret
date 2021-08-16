#include<stdio.h>
#include<stdlib.h>

#include "../headers/list_number.h"

int main(){

    struct list_number *lt = list_number_new();

    printf("%s", list_number_to_str(lt));
    
    struct list_number *element_0 = list_number_get_by_index(lt, 0);
    printf("%d %lf %p\n",
        list_number_get_number(element_0),
        list_number_get_score(element_0),
        list_number_get_list_teammate(element_0)
    );
    

   //printf("%d\n", list_number_get_number(list_number_get_by_index(lt,8)));



    /* 
    int *test_set = list_number_propose_for_test(lt);
    printf("%d %d %d %d\n", test_set[0], test_set[1], test_set[2], test_set[3]);
    free(test_set);
    */

    /*
    int *test_set = list_number_propose_for_discovery(lt, 0);
    printf("%d %d %d %d\n", test_set[0], test_set[1], test_set[2], test_set[3]);
    free(test_set);
    */

    /*
    printf("%d\n",
        list_number_get_number(list_number_get_by_number(lt, 6))
    );
    */

   /*
   list_number_update_score(lt, 0);
   printf("%lf\t%d\n", list_number_get_score(lt), list_number_get_participation_number(lt));
    */

    return 0;
}