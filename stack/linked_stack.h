/* 链栈 头文件 */
#ifndef _linked_stack_h_
#define _linked_stack_h_


#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>


typedef int DataType;
//链式存储栈的节点定义
typedef struct LinkedStackNode{
        struct LinkedStackNode *next;
        DataType data;
}LinkedStackNode, *LinkedStackNodePtr;
//链栈的结构定义
typedef struct LinkedStack{
        struct LinkedStackNode *top;
        int length;
}LinkedStack, *LinkedStackPtr;


void init_l(LinkedStackPtr lstack);                  //初始化   
bool isEmpty_l(LinkedStackPtr lstack);                //判断空
void push_l(LinkedStackPtr lstack, DataType data);           //入栈
DataType pop_l(LinkedStackPtr lstack);        //出栈  
int get_length_l(LinkedStackPtr lstack);                //获取栈长度
DataType get_top_l(LinkedStackPtr lstack);    //获取栈顶元素值
void destroy_l(LinkedStackPtr lstack);        //销毁

#endif
