#ifndef _linked_list_h_
#define _linked_list_h_

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>


typedef int DataType;

typedef struct linked_node{
        DataType data;
        struct linked_node *next;
}linked_node, *linked_node_ptr;

typedef struct linked_list{
        int length;
        struct linked_node *head;
        struct linked_node *tails;
}linked_list, *linked_list_ptr;


linked_list_ptr init_1(linked_list_ptr linked1);  //初始化
linked_node_ptr create_node1(DataType data);   //生成节点
void insert_h(linked_list_ptr linked1, DataType data);        //头插法插入节点
void insert_t(linked_list_ptr linked1, DataType data);        //尾插法插入节点
int get_length_1(linked_list_ptr linked1);    //获取链表长度
void add_node_1(linked_list_ptr linked1, int position, DataType data);          //在指定位置添加节点
void remove_node_1(linked_list_ptr linked1, int position);   //移除指定位置上的节点
linked_node_ptr find_node_data_1(linked_list_ptr linked1, DataType fdata);    //根据传入的数据查找并返回该节点的地址
void alter_node_data_1(linked_list_ptr linked1, int position, DataType data);     //修改节点，根据位置修改数据
void destroy_linked_1(linked_list_ptr linked1);        //销毁链表
void print_linked(linked_list_ptr linked1);        //循环遍历


#endif
