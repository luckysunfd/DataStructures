#include "seq_queue.h"




int main(void){
        SeqQueuePtr queue = (SeqQueuePtr)malloc(sizeof(SeqQueue));
        if(queue == NULL){
                puts("内存分配错误");
                exit(-1);
        }

        puts("initial >>");
        init(queue, MAXSIZE);

        puts("入队 >>");
        for(int i = 0; i < MAXSIZE; i++){
                enter_queue(queue, i);
        }

        puts("此时的队列长度");
        printf("%d\n", get_cnt(queue));

        puts("出队 >>");
        printf("%d\n", del_queue(queue));
        printf("%d\n", del_queue(queue));
        printf("%d\n", del_queue(queue));

        printf("此时的队列长度 %d\n", get_cnt(queue));

        return 0;
}