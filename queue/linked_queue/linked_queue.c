/* 链式队列实现文件 */

#include "linked_queue.h"




//初始化
void init(LinkedQueuePtr lq1){
        lq1->cnt = 0;
        lq1->front = NULL;
        lq1->rear = NULL;
}

//判空
bool is_Empty(LinkedQueuePtr lq1){
        if(lq1 == NULL || lq1->cnt == 0){
                return true;
        }else{
                return false;
        }
}

//求队列长度
int get_length(LinkedQueuePtr lq1){
        if(is_Empty(lq1)){
                return 0;
        }else{
                return lq1->cnt;
        }
}

//
LinkedQueueNodePtr create_node(DataType data){
        LinkedQueueNodePtr node = (LinkedQueueNodePtr)malloc(sizeof(LinkedQueueNode));
        if(node == NULL){
                puts("Memory allocation failed");
                return NULL;
        }else{
                node->data = data;
                node->next = NULL;

                return node;
        }
}

//进队
void enter_queue(LinkedQueuePtr lq1, DataType data){
        if(lq1 == NULL){
                puts("循环队列未初始化，暂不支持入队操作");
                return ;
        }else{
                LinkedQueueNodePtr node = create_node(data);
                if(node == NULL){
                        puts("Memory allocation failed");
                        return ;
                }
                if(lq1->front == NULL){
                        lq1->front = node;
                        lq1->rear = node;
                        lq1->cnt++;
                }else{
                        lq1->rear->next = node;
                        lq1->rear = node;
                        lq1->cnt++;
                }
        }
}

//出队
DataType delete_queue(LinkedQueuePtr lq1){
        if(is_Empty(lq1)){
                puts("Empty queue");
                return 0;
        }else{
                LinkedQueueNodePtr temp = lq1->front->next;
                DataType d = lq1->front->data;
                free(lq1->front);
                lq1->front = temp;
                lq1->cnt--;
                if(lq1->front == NULL)
                        lq1->rear = NULL;

                return d;
        }
}