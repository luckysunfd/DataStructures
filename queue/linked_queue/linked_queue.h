/**
 * @author      : sun (lingganyang@gmail.com)
 * @file        : linked_queue
 * @created     : Saturday Dec 01, 2018 22:47:09 CST
 */

#ifndef LINKED_QUEUE_H

#define LINKED_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

typedef int DataType;

typedef struct LinkedQueueNode{
        DataType data;
        struct LinkedQueueNode *next;
}LinkedQueueNode, *LinkedQueueNodePtr;

typedef struct LinkedQueue{
        LinkedQueueNodePtr front;
        LinkedQueueNodePtr rear;
        int length;
}LinkedQueue, *LinkedQueuePtr; 


void init_linked_queue(LinkedQueuePtr lq1);   //初始化
bool is_empty(LinkedQueuePtr lq1);          //判断是否为空
int get_length_linked_queue(LinkedQueuePtr lq1);     //获取队列长度
LinkedQueueNodePtr create_node(DataType data);   //生成一个队列节点
void enter_queue(LinkedQueuePtr lq1, DataType data);          //进队
DataType delete_queue(LinkedQueuePtr lq1);     //出队


#endif /* end of include guard LINKED_QUEUE_H */

