#include <stdio.h>
#include <stdlib.h>

#include "list.h"

#define NAMESIZE 32

struct score_st
{
    int id;
    char name[NAMESIZE];
    struct list_head node;
    int math;
    int chinese;
};

void printf_s(struct score_st *datap)
{
    printf("%d %s %d %d\n", datap->id, datap->name, datap->math, datap->chinese);
}

int main ()
{
    struct score_st *datap;
    struct list_head *cur;
    int i;
    LIST_HEAD(head);


    for(i = 0; i < 8; i++)
    {
        datap = malloc(sizeof(*datap));
        if(datap == NULL)
            exit(1);

        datap->id = i;
        snprintf(datap->name, NAMESIZE, "stu%d", i);
        datap->math = rand() % 100;
        datap->chinese = rand() % 100;

        list_add(&datap->node, &head);
    }

    list_for_each(cur, &head)
    {
        datap = list_entry(cur, struct score_st, node);
        printf_s(datap);
    }

    printf("\n");

    list_for_each(cur, &head)
    {
        datap = list_entry(cur, struct score_st, node);
        if(datap->id == 15)
            break;
    }

    if(cur != &head)
        printf_s(datap);
    else
        printf("Not found\n");

    exit(0);
}