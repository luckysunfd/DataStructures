/**
 * @author      : sun 
 * @file        : seq_stack
 * @created     : Thursday Dec 06, 2018 22:31:26 CST
 */

#include "seq_stack.h"




void init(SeqQueuePtr queue, int len){
        queue->pBase = (DataType *)malloc(sizeof(DataType) * len);
        if(queue->pBase == NULL){
                puts("Memory allocation failed");
                return ;
        }

        queue->top = -1;
        queue->cnt = 0;
}

bool is_full(SeqQueuePtr queue){
        if(MAXSIZE == queue->cnt){
                return true;
        }else{
                return false;
        }
}

bool is_empty(SeqQueuePtr queue){
        if(queue->cnt == 0){
                return true;
        }else{
                return false;
        }
}

DataType pop(SeqQueuePtr queue){
        if(is_empty(queue)){
                return 0;
        }else{
                queue->cnt--;
                return queue->pBase[queue->top--];
        }
}

void push(SeqQueuePtr queue, DataType data){
        if(is_full(queue)){
                puts("it\'s full");
                return ;
        }else{
                queue->cnt++;
                queue->pBase[++queue->top] = data;
        }
}

int get_length(SeqQueuePtr queue){
        return queue->cnt;
}

DataType get_top(SeqQueuePtr queue){
        if(is_empty(queue)){
                return 0;
        }else{
                return queue->pBase[queue->top];
        }
}