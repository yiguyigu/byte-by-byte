#ifndef SQLIST_H__
#define SQLIST_H__

#define DATESIZE 1024
typedef int datatype;

typedef struct node_st
{
    datatype data[DATESIZE];
    int last;
}sqlist;

/*
 * 两种方式创建线性表
 * 1.返回结构体指针
 * 2.传入二级指针，创建失败返回空指针
*/ 
sqlist *sqlist_create1();
void sqlist_create2(sqlist **list);

int sqlist_insert(sqlist *list, int pos, datatype *data);

int sqlist_delete(sqlist *list, int pos);

int sqlist_find(sqlist *list, datatype *data);

int sqlist_isempty(sqlist *list);

int sqlist_set_empty(sqlist *list);

int sqlist_get_length(sqlist *list);

void sqlist_display(sqlist *list);

int sqlist_destroy(sqlist *list);

int sqlist_union(sqlist *list1, sqlist *list2);


#endif