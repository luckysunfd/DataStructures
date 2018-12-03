#ifndef _CLINKED_LIST_H_
#define _CLINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>


typedef int DataType;

typedef struct cLinkedListNode{
        DataType data;
        struct cLinkedListNode *next;
}cLinkedListNode, *cLinkedListNodePtr;

typedef struct cLinkedList{
        cLinkedListNodePtr head;
        cLinkedListNodePtr tails;
        int length;
}cLinkedList, *cLinkedListPtr;

void init(cLinkedListPtr clinked_list);
cLinkedListNodePtr create_node(DataType data);
void insert_node_2tails(cLinkedListPtr clinked_list, DataType data);
void insert_node_2head(cLinkedListPtr clinked_list, DataType data);
void visit(cLinkedListPtr clinked_list);
cLinkedListNodePtr find_node(cLinkedListPtr clinked_list, DataType fdata);
void del_node(cLinkedListPtr clinked_list, int position);
void alter_node(cLinkedListPtr clinked_list, int position, DataType data);
bool is_empty(cLinkedListPtr clinked_list);
int get_length(cLinkedListPtr clinked_list);

#endif

