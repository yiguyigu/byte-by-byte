#ifndef NOHEAD_H__
#define NOHEAD_H__

#define NAMESIZE 32

struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};

struct node_st
{
    struct score_st data;
    struct node_st *next;
};


struct node_st * list_insert_fistleve(struct node_st *me, struct score_st *data);//When defining a function, the name of the parameter can be omitted, but the type must be specified
int list_insert(struct node_st **me, struct score_st *data);

void list_display(struct node_st *me);

int list_delete(struct node_st **me);

int list_find_print(struct node_st *, int id);
struct score_st * list_find(struct node_st *, int id);

void list_destroy(struct node_st *me);

#endif