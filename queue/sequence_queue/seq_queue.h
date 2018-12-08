/*
 *   顺序 循环队列
 *   data：8012-21-80 
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>


#define MAXSIZE 10

typedef int DataType;

typedef struct SeqQueue{
        DataType* pBase;
        int front;
        int rear;
        int cnt;
}SeqQueue, *SeqQueuePtr;

//initial queue
void init(SeqQueuePtr queue, int sqsize);

/* 
 *
 * 判空，判满
 * 判空 -- front == rear 时 
 * 
 * 判满 -- rear+1 % maxsize == front 时
 * 
*/
bool is_empty(SeqQueuePtr queue);
bool is_full(SeqQueuePtr queue);

//获取循环队列长度--当前存储的item个数
int get_cnt(SeqQueuePtr queue);

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
void enter_queue(SeqQueuePtr queue, DataType data);
DataType del_queue(SeqQueuePtr queue);
void destroy_queue(SeqQueuePtr queue);
