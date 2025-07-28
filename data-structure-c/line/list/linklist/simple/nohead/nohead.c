#include <stdio.h>
#include <stdlib.h>

#include "nohead.h"


struct node_st * list_insert_fistleve(struct node_st *me, struct score_st *data)
{
    /*
    * This is achieved by passing in a first-level pointer
    * A linked list header must be returned to the top
    */

    struct node_st *newnode;
    newnode = malloc(sizeof(*newnode));
    if(newnode == NULL)
        return NULL;
    newnode->data = *data;
    // newnode->next = NULL; //this is a good way when creat a new post to set NULL
    newnode->next = me;
    me = newnode;
    return me;
}

int list_insert(struct node_st **me, struct score_st *data)
{
    struct node_st *newnode;
    newnode = malloc(sizeof(*newnode));
    if(newnode == NULL)
        return -1;
    newnode->data = *data;
    newnode->next = *me;
    *me = newnode;
    return 0;
}

void list_display(struct node_st *me)
{
#if 0
    /*It is not recommended to use while loops, as the last node is ignored and the value of the incoming me may be modified*/
    while(me->next != NULL)
    {
        printf("%d %s %d %d\n", me->data.id, me->data.name, me->data.math, me->data.chinese);
        //address use "->" ; constant data use "."
        me = me->next;
    }
#endif
    struct node_st *cur;
    for(cur = me; cur != NULL; cur = cur->next)
    {
        printf("%d %s %d %d\n", cur->data.id, cur->data.name, cur->data.math, cur->data.chinese);
    }
}

int list_delete(struct node_st **me)
{
    struct node_st *cur;
    if(*me == NULL)
        return -1;

    cur = *me;
    *me = (*me)->next;
    free(cur);
    return 0;
}

/*
* Generally, this is not used, because whether printing is needed should be decided by the main.
*/
int list_find_print(struct node_st *me, int id)
{
    struct node_st *cur;
    for(cur = me; cur != NULL; cur = cur->next)
    {
        if(cur->data.id == id)
        {
            printf("%d %s %d %d\n", cur->data.id, cur->data.name, cur->data.math, cur->data.chinese);
            return 0;  
        }
    }
    return -1;
}

/*
* This is used when the return value is needed
*/
struct score_st * list_find(struct node_st *me, int id)
{
    struct node_st *cur;
    for(cur = me; cur != NULL; cur = cur->next)
    {
        if(cur->data.id == id)
        {
            return &cur->data;
        }
    }
    return NULL;
}

void list_destroy(struct node_st *me)
{
    struct node_st *cur;
    if(me == NULL)
        return;

    for(cur = me; cur != NULL; cur = me)
    {
        me = me->next;
        free(cur);
    }
}