#include<stdio.h>
#include<stdlib.h>

#include "sqlist.h"

int main()
{
    sqlist *list = NULL;
    sqlist *list1 = NULL;
    datatype arr[] = {12,23,34,45,56};
    datatype arr1[] = {98,23,27,45,50};
    int i;
    int err;

    list = sqlist_create1(); //一种是通过传参将指针带回
    // sqlist_create2(&list); //另一种是通过传入二级指针，完成对一级指针的赋值
    if(list == NULL)
    {
        fprintf(stderr, "sqlist_create1() failed!\n");
        exit(1);
    }
    sqlist_create2(&list1);
    if(list1 == NULL)
    {
        fprintf(stderr, "sqlist_create1() failed!\n");
        exit(1);
    }

    for(i =0; i < sizeof(arr)/sizeof(*arr); i++)
    {
        if((err = sqlist_insert(list, 0, &arr[i])) != 0)
        {
            if(err == -1)
            {
                fprintf(stderr, "The arr is full!\n");
            }
            else if(err == -2)
            {
                fprintf(stderr, "The pos you want to insert is wrong!\n");
            }
            else
            {
                fprintf(stderr, "ERROR!\n");
            }
            exit(1);
        }
    }
    
    for(i = 0; i < sizeof(arr1)/sizeof(*arr1); i++)
        err = sqlist_insert(list1, 0, &arr1[i]);
        
    sqlist_display(list);
    sqlist_display(list1);
    sqlist_union(list, list1);
    sqlist_display(list);

#if 0
    sqlist_delete(list, 2);

    sqlist_display(list);
#endif
    sqlist_destroy(list);
    sqlist_destroy(list1);

    exit(0);
}