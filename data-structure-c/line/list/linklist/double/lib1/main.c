#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "llist.h"

struct score_st
{
    int id;
    char name[32];
    int math;
    int chinese;
};

static void print_s(const void *record)
{
    const struct score_st *r = record;

    printf("%d %s %d %d\n", r->id, r->name, r->math, r->chinese);
}

static int id_cmp(const void *key, void *record)
{
    const int *k = key;
    const struct score_st *r = record;

    return (*k - r->id);
}

static int name_cmp(const void *key, void *record)
{
    const char *k = key;
    const struct score_st *r = record;

    return strcmp(k, r->name);
}

int main()
{
    LLIST *handler;
    struct score_st tmp;
    int i, ret;
    int id = 3;
    char *name = "stu3";
    struct score_st *data;

    handler = llist_create(sizeof(struct score_st));
    if(handler == NULL)
        exit(1);

    for(i = 0; i < 8; i++)
    {
        tmp.id = i;
        snprintf(tmp.name, sizeof(tmp.name), "stu%d", i);
        tmp.math = rand() % 100;
        tmp.chinese = rand() % 100;

        ret = llist_insert(handler, &tmp, LLIST_BACKWARD);
        if(ret)
            exit(1);
    }

    llist_travel(handler, print_s);

    printf("\n\n");

    ret = llist_delete(handler, name, name_cmp);
    if(ret)
        printf("Can't find the item.\n");

    llist_travel(handler, print_s);
    
#if 0
    data = llist_find(handler, &id, id_cmp);
    if(data == NULL)
        printf("Can't find the item.\n");
    else
        print_s(data);
#endif

    llist_destroy(handler);

    exit(0);
}