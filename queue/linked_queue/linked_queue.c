/**
 * @author      : sun (lingganyang@gmail.com)
 * @file        : linked_queue
 * @created     : Saturday Dec 01, 2018 23:02:49 CST
 */

#include "linked_queue.h"


void init_linked_queue(LinkedQueuePtr lq1){
        lq1->front = NULL;
        lq1->rear  = NULL;
        lq1->length = 0;
}

bool is_empty(LinkedQueuePtr lq1){
        if(lq1->front == NULL && lq1->rear == NULL){
                return true;
        }else{
                return false;
        }
}

int get_length_linked_queue(LinkedQueuePtr lq1){
        return lq1->length;
}

LinkedQueueNodePtr create_node(DataType data){
        LinkedQueueNodePtr node = (LinkedQueueNodePtr)malloc(sizeof(LinkedQueueNode));
        if(node == NULL){
                puts("Memory allocation error");
                return NULL;
        }else{
                node->data = data;
                node->next = NULL;
        }
        return node;
}

void enter_queue(LinkedQueuePtr lq1, DataType data){
        LinkedQueueNodePtr node = create_node(data);
        if(node == NULL){
                puts("因创建节点失败导致入队失败");
                return ;
        }

        if(lq1->front == NULL){
                lq1->front = node;
                lq1->rear  = node;
                lq1->length++;
        }else{
                lq1->rear->next = node;
                lq1->rear = node;
                lq1->length++;
        }
}

DataType delete_queue(LinkedQueuePtr lq1){
        LinkedQueueNodePtr temp = lq1->front->next;  // store next node
        
        if(temp == NULL){
                DataType return_data = lq1->front->data;
                free(lq1->front);
                lq1->front = NULL;
                lq1->rear  = NULL;
                lq1->length--;

                return return_data;
        }else{
                DataType return_data = lq1->front->data;
                free(lq1->front);
                lq1->front = temp;
                lq1->length--;

                return return_data;
        }
}
