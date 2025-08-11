#include <stdio.h>
#include <stdlib.h>

#include "sqstack.h"

int main()
{
    sqstack *stack;
    int i, ret;
    datatype arr[] = {12, 34, 56, 78, 90};

    stack = st_creat();
    if(stack == NULL)
        exit(1);

    for(i = 0; i < sizeof(arr)/sizeof(*arr); i++)
        st_push(stack, &arr[i]);

    st_travel(stack);
    
#if 1
    datatype tmp;
    while(st_pop(stack, &tmp) == 0)
        printf("POP: %d\n", tmp);

#else 
    datatype tmp = 1;
    ret = st_push(stack, &tmp);
    if(ret == 0)
        st_travel(stack);
    else
        printf("st_push failed!\n");
#endif

    st_destroy(stack);

    exit(0);
}