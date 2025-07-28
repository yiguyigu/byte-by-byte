#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main()
{
    list *l;
    int i;
    datatype arr[] = {12,23,8,34,9,4,45};

    l = list_create();
    if(l == NULL)
        exit(1);

    for(i = 0; i < (sizeof(arr)/sizeof(*arr)); i++)
    {
        // if(list_inster_at(l, 0, &arr[i]))
        if(list_order_inster(l, &arr[i]))
            exit(1);
        
    }

    list_display(l);

    datatype value;
    int err;
    err = list_delete_at(l, 3, &value);
    if(err)
        exit(1);
    list_display(l);
    printf("delete : %d\n",value);
    

#if 0
    datatype value = 8;
    list_delete(l, &value);
    list_display(l);
#endif

    list_destroy(l);

    exit(0);
}