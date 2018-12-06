/**
 * @author      : sun 
 * @file        : seq_stack
 * @created     : Thursday Dec 06, 2018 22:31:41 CST
 */

#ifndef SEQ_STACK_H

#define SEQ_STACK_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MAXSIZE 10

typedef int DataType;

typedef struct SeqQueue{
        DataType* pBase;
        int top;
        int cnt;
}SeqQueue, *SeqQueuePtr;

void init(SeqQueuePtr queue, int len);
bool is_full(SeqQueuePtr queue);
bool is_empty(SeqQueuePtr queue);
DataType pop(SeqQueuePtr queue);
void push(SeqQueuePtr queue, DataType data);
int get_length(SeqQueuePtr queue);
DataType get_top(SeqQueuePtr queue);


#endif /* end of include guard SEQ_STACK_H */

