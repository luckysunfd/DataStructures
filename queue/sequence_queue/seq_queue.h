/**
 * @author      : sun (lingganyang@gmail.com)
 * @file        : seq_queue
 * @created     : Saturday Dec 01, 2018 12:08:53 CST
 */

#ifndef SEQ_QUEUE_H

#define SEQ_QUEUE_H


#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#define MAXSIZE 10

typedef int DataType;

typedef struct SeqQueue{
        DataType *pBase;
        int front;
        int rear;
}SeqQueue, *SeqQueuePtr;

void init_seq_queue(SeqQueuePtr sq1, int length);
bool is_full_seq_queue(SeqQueuePtr sq1);
bool is_empty_seq_queue(SeqQueuePtr sq1);
void enter_seq_queue(SeqQueuePtr sq1, DataType data);
DataType delete_seq_queue(SeqQueuePtr sq1);
int get_length_seq_queue(SeqQueuePtr sq1);


#endif /* end of include guard SEQ_QUEUE_H */

