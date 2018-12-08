#include "seq_queue.h"




//initial queue
void init(SeqQueuePtr queue, int sqsize){
        queue->pBase = (DataType *)malloc(sizeof(DataType) * MAXSIZE);   //在堆上分配存储空间
        queue->front = 0;
        queue->rear = 0;
        queue->cnt = 0;
}

/* 
 *
 * 判空，判满
 * 判空 -- front == rear 时 
 * 
 * 判满 -- rear+1 % maxsize == front 时
 * 
*/
bool is_empty(SeqQueuePtr queue){
        if(queue->rear == queue->front){
                return true;
        }else{
                return false;
        }
}

bool is_full(SeqQueuePtr queue){
        if( (queue->rear + 1) % MAXSIZE == queue->front){
                return true;
        }else{
                return false;
        }
}

//获取循环队列长度--当前存储的item个数
int get_cnt(SeqQueuePtr queue){
        if(queue == NULL || queue->cnt == 0){
                return 0;
        }else{
                return queue->cnt;
        }
}

/*
 *  出入队 
 *  
 *  为了能够正确的判断队列空，满状态， 需要牺牲一个存储位置，也就是说一个队列内的一个
 *  元素不存储数据,因为如果都利用起来，那么队空状态下rear，front指针都指向同一个地方
 *  队满状态下rear， front也是指向同一个地方
 *   
 *  队列的循环， 内存地址是线性平坦的，单纯利用物理上的特性无法实现地址的循环
 *  通过手动列出所有的地址，可以发现 这些地址的集合 是模为队列maxsize的余数， 所以用 取模 实现地址的循环利用
 *    
 *  入队 rear+1 % maxsize = data
 *  出队 return front+1 % maxsize
 * 
*/
void enter_queue(SeqQueuePtr queue, DataType data){
        if(is_full(queue)){
                puts(" 队列已满，暂不支持入队操作，请稍后再试");
                return ;
        }else{
                queue->rear = (queue->rear + 1) % MAXSIZE;
                queue->pBase[queue->rear] = data;
                queue->cnt++;
        }
}

DataType del_queue(SeqQueuePtr queue){
        if(is_empty(queue)){
                puts("队列已空，暂不支持出队操作，请稍后再试");
                return 0;
        }else{
                queue->cnt--;
                queue->front = (queue->front + 1) % MAXSIZE;
                return queue->pBase[queue->front];
        }
}

void destroy_queue(SeqQueuePtr queue){
        if(queue == NULL){
                puts("队列未初始化");
                return ;
        }

        free(queue->pBase);
        queue->front = 0;
        queue->rear = 0;
}