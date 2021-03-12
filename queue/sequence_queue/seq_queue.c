#include "seq_queue.h"




void init_seq_queue(SeqQueuePtr sq1, int length){
        sq1->pBase = (DataType *)malloc(sizeof(DataType) * length);
        if(sq1->pBase == NULL){
                puts("Memory allcation error!");
                exit(-1);
        }
        sq1->front = 0;
        sq1->rear  = 0;
}

bool is_full_seq_queue(SeqQueuePtr sq1){
        if((sq1->rear + 1) % MAXSIZE == sq1->front){
                return true;
        }else{
                return false;
        }
}

bool is_empty_seq_queue(SeqQueuePtr sq1){
        if(sq1->rear == sq1->front){
                return true;
        }else{
                return false;
        }
}

void enter_seq_queue(SeqQueuePtr sq1, DataType data){
        if(is_full_seq_queue(sq1)){
                puts("Queue is full!");
        }else{
                sq1->rear = (sq1->rear + 1) % MAXSIZE;
                sq1->pBase[sq1->rear] = data;
        }
}

DataType delete_seq_queue(SeqQueuePtr sq1){
        if(is_empty_seq_queue(sq1)){
                puts("Queue is empty");
        }else{
                sq1->front = (sq1->front + 1) % MAXSIZE;
                return sq1->pBase[sq1->front];
        }
}