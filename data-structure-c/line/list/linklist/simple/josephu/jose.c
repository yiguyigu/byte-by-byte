#include <stdio.h>
#include <stdlib.h>

#define JOSE_NUM 8

struct node_st
{
    int data;
    struct node_st *next;
};

struct node_st *jose_create(int n)
{
    struct node_st *head, *cur, *newnode;
    int i;

    head = malloc(sizeof(*head));
    if(head == NULL)
        return NULL;
    head->data = 1;
    head->next = head;

    cur = head;
    for(i = 2; i <= n; i++)
    {
        newnode = malloc(sizeof(*newnode));
        if(newnode == NULL)
            return NULL;
        newnode->data = i;
        newnode->next = head;
        cur->next = newnode;
        cur = newnode;
    }

    return head;
}

void jose_display(struct node_st *me)
{
    struct node_st *cur;

    for(cur = me; cur->next != me; cur = cur->next)
    {
        printf("%d ", cur->data);
    }
    printf("%d\n", cur->data);
}

#if 0
// this have a bug, when display, the list is changed
void jose_kill(struct node_st *me, int n)
{
    struct node_st *cur = me, *node;
    int i = 1;
    while(cur->next != cur)
    {
        while(i < n)
        {
            node = cur;
            cur = cur->next;
            i++;
        }
        printf("%d ", cur->data);
        node->next = cur->next;
        free(cur);

        cur = node->next;
        i = 1;
    }
    printf("\n");
}
#endif
void jose_kill(struct node_st **me, int n)
{
    struct node_st *cur = *me, *node;
    int i = 1;
    while(cur->next != cur)
    {
        while(i < n)
        {
            node = cur;
            cur = cur->next;
            i++;
        }
        printf("%d ", cur->data);
        node->next = cur->next;
        free(cur);

        cur = node->next; // Without this, a serious error will occur because the outer while loop will keep looping
        i = 1;
    }
    *me = cur;
    printf("\n");
}

int main()
{
    struct node_st *list;
    int step = 3;

    list = jose_create(JOSE_NUM);
    if(list == NULL)
        exit(1);

    jose_display(list);

    jose_kill(&list, step);

    jose_display(list);

    return 0;
}