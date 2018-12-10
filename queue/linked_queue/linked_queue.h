/*
 * 循环队列 -- 链式存储
 * 套用循环单链表就可以
 * 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>


typedef int DataType;

//链式队列单节点
typedef struct LinkedQueueNode{
        DataType data;
        struct LinkedQueueNode *next;
}LinkedQueueNode, *LinkedQueueNodePtr;

//链式循环队列
typedef struct LinkedQueue{
        int cnt;    //队列长度
        LinkedQueueNodePtr front;   //队头指针 -- 头出 
        LinkedQueueNodePtr rear;    //队尾指针 -- 尾进 --尾插法插入
}LinkedQueue, *LinkedQueuePtr;


//初始化
void init(LinkedQueuePtr lq1);
//判空
bool is_Empty(LinkedQueuePtr lq1);
//求队列长度
//创建节点
LinkedQueueNodePtr create_node(DataType data);
int get_length(LinkedQueuePtr lq1);
//进队
void enter_queue(LinkedQueuePtr lq1, DataType data);
//出队
DataType delete_queue(LinkedQueuePtr lq1);


