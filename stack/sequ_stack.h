/* 
 * 栈的顺序实现头文件，基于数组存储
 *
 * */
#ifndef _sequ_stack_h_
#define _sequ_stack_h_

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAXSIZE 100

typedef int DataType;

/*
 * 栈的逻辑结构，包含指向栈顶的栈顶指针以及存储栈元素的空间
 * 反应到物理存储结构上，由于是顺序栈，采用的数组这种物理上连续的地址空间，显然，可以用一个结构体来整合上面的两点
 * 1. 栈顶指针， 对数组元素的访问使用的下表偏移，所以采用整型变量来落地栈顶指针
 * 2. 栈存储空间， 显然，采用数组变量就可以了，定义时给定明确的数组大小即可
 */
typedef struct sequ_stack{
        int top;
        DataType ele[MAXSIZE];
}sequ_stack, *sequ_stackPtr;

void init_s(sequ_stackPtr sstack);
int get_length(sequ_stackPtr sstack);
void push(sequ_stackPtr sstack, DataType data);
DataType pop(sequ_stackPtr sstack);
DataType get_top_element(sequ_stackPtr sstack);
bool is_empty1(sequ_stackPtr sstack);
bool is_full(sequ_stackPtr sstack);


#endif
