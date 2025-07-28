#include <stdio.h>
#include <stdlib.h>

#include "nohead.h"

int main(void)
{
    struct node_st *list = NULL;
    struct score_st tmp;
    int i, ret;

    for(i = 0; i < 7; i++)
    {
        tmp.id = i;
        snprintf(tmp.name, NAMESIZE, "stu%d", i);//tmp.name is a array, like a pointer constant,so we can't assign it directly
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;

        ret = list_insert(&list, &tmp);
        if(ret)
            exit(1);
    }
    list_display(list);

    // printf("\nfind one node\n\n");
    // list_find_print(list, 13);

    struct score_st *data = list_find(list, 1);
    if(data == NULL)
        printf("not found\n");
    else
        printf("\n%d %s %d %d\n", data->id, data->name, data->math, data->chinese);

    // list_delete(&list);
    // printf("\ndelete one node\n\n");
    // list_display(list);

    list_destroy(list);
    
    exit(0);
}