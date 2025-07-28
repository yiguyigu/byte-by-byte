#include <stdio.h>
#include <stdlib.h>

struct node_st
{
    int exp;
    int coef;
    struct node_st *next;
};

struct node_st * poly_create(int arr[][2], int n)
{
    int i;
    struct node_st *me;
    struct node_st *new_node, *cur;
    me = malloc(sizeof(*me));
    if(me == NULL)
        return NULL;
    me->next = NULL;

    cur = me;

    for(i = 0; i < n; i++)
    {
        new_node = malloc(sizeof(*new_node));
        if(new_node == NULL)
            return NULL;
        new_node->exp = arr[i][1];
        new_node->coef = arr[i][0];
        new_node->next = NULL;

        cur->next = new_node;
        cur = new_node;
    }
    return me;
}

void poly_display(struct node_st *me)
{
    struct node_st *cur;
    for(cur = me->next; cur != NULL; cur = cur->next)
    {
        printf("(%d %d) ", cur->coef, cur->exp);
    }
    printf("\n");
}

void poly_union(struct node_st *p1, struct node_st *p2)
{
    struct node_st *p, *q, *r;
    p = p1->next;
    q = p2->next;
    r = p1;//this is used to keep the last node of the result list


    while(p && q)
    {
        if(p->exp > q->exp)
        {
            r->next = q;
            r = q;
            q = q->next;
        }
        else if(p->exp < q->exp)
        {
            r->next = p;
            r = p;
            p = p->next;
        }
        else
        {
            p->coef += q->coef;
            if(p->exp)
            {
                r->next = p;
                r = p;
            }
            p = p->next;
            q = q->next;
        }
    }
    if(p)
        r->next = p;
    else
        r->next = q;
}

int main()
{
    struct node_st *p1, *p2;
    int arr1[][2] = {{5, 0}, {2, 1}, {8, 8}, {3, 16}};
    int arr2[][2] = {{6, 1}, {16, 6}, {-8, 9}};


    p1 = poly_create(arr1, 4);
    p2 = poly_create(arr2, 3);
    poly_display(p1);
    poly_display(p2);

    poly_union(p1, p2);
    poly_display(p1);

    return 0;
}