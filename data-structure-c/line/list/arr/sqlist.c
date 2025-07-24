#include <stdio.h>
#include <stdlib.h>

#include "sqlist.h"

sqlist *sqlist_create1()
{
    sqlist *me;//这是一个指向结构体的指针，sizeof(*me)表示的是这个结构体大小

    me = malloc(sizeof(*me));
    if(me == NULL)
    {
        return NULL;
    }
    me -> last = -1;

    return me;
}

void sqlist_create2(sqlist **ptr)
{

    *ptr = malloc(sizeof(**ptr));
    if(*ptr == NULL)
        return;

    (*ptr) -> last = -1;//优先级问题，先取*ptr，再取->last

    return;

}

int sqlist_insert(sqlist *me, int pos, datatype *data)
{
    int i;

    if(me->last == DATESIZE - 1)
        return -1;

    if(pos < 0 || pos > me->last + 1)
        return -2;

    for(i = me->last; pos <= i; i--)
        me->data[i + 1] = me->data[i];
    
    me->data[pos] = *data;
    me->last++;

    return 0;
}

int sqlist_delete(sqlist *me, int pos)
{
    int i;
    if(pos < 0 || pos > me->last)
        return -1;

    for(i = pos; i <= me->last; i++)
    {
        me->data[i] = me->data[i + 1];
    }
    
    me->last--;

    return 0;
}

int sqlist_find(sqlist *me, datatype *data)
{
    int i;
    if(sqlist_isempty == 0)
        return -1;

    for(i = 0; i <= me->last; i++)
    {
        if(me->data[i] == *data)
            return i;
    } 

    return -2;
}

int sqlist_isempty(sqlist *me)
{
    if(me->last == -1)
        return 0;
    return -1;
}

int sqlist_set_empty(sqlist *me)
{
    me->last = -1;
    return 0;
}

int sqlist_get_number(sqlist *me)
{
    return (me->last + 1);
}

void sqlist_display(sqlist *me)
{
    int i;
    if(me->last == -1)
        return;

    for(i = 0; i <= me->last; i++)
    {
        printf("%d ", me->data[i]);
    }
    printf("\n");
    return;
}

int sqlist_destroy(sqlist *me)
{
    free(me);
    return 0;
}


int sqlist_union(sqlist *list1, sqlist *list2)
{
    int i = 0;

    for(i = 0; i <= list2->last; i++)
    {
       if(sqlist_find(list1,&list2->data[i]) < 0)
        {
            sqlist_insert(list1, list1->last + 1, &list2->data[i]);
        }
    }

}