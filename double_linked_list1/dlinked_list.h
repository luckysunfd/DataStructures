/**
 * @author      : sun 
 * @file        : dlinked_list
 * @created     : Wednesday Dec 05, 2018 11:55:48 CST
 */

#ifndef DLINKED_LIST_H

#define DLINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>


typedef int DataType;
//定义链表节点
typedef struct DLinkedListNode{
        DataType data;
        struct DLinkedListNode *previous; //指向前一个节点
        struct DLinkedListNode *next;     //指向后一个节点
}DLinkedListNode, *DLinkedListNodePtr;
//定义双链表，包含头尾节点，链表长度
typedef struct DLinkedList{
        DLinkedListNodePtr head;      //指向头节点
        DLinkedListNodePtr tails;     //指向尾节点
        int length;
}DLinkedList, *DLinkedListPtr;


//初始化
void init_dlinked(DLinkedListPtr dlinked);
//生成节点
DLinkedListNodePtr create_node(DataType data);
//插入节点 -- 头插法
void insert_nodeh(DLinkedListPtr dlinked, DataType data);
//尾插法
void insert_nodet(DLinkedListPtr dlinked, DataType data);
//遍历
void visit_l(DLinkedListPtr dlinked);
//查找节点，传入一个数据，返回第一个 数据相等的节点指针
DLinkedListNodePtr find_node(DLinkedListPtr dlinked, DataType fdata);
//删除节点,传入一个链表位置，然后删除它
void del_node(DLinkedListPtr dlinked, int position);
//修改节点
void alter_node(DLinkedListPtr dlinked, int position, DataType data);
//求链表长度
int get_length(DLinkedListPtr dlinked);
//插入节点，根据传入的位置参数插入
void insert_node2_n(DLinkedListPtr dlinked, int position, DataType data);
//判空
bool is_empty(DLinkedListPtr dlinked);
//销毁双向链表
void destroy_dlinked(DLinkedListPtr dlinked);

#endif /* end of include guard DLINKED_LIST_H */

