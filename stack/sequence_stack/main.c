/**
 * @author      : sun 
 * @file        : main
 * @created     : Thursday Dec 06, 2018 22:30:39 CST
 */

#include "seq_stack.h"




int main(void){
        SeqQueuePtr queue = (SeqQueuePtr)malloc(sizeof(SeqQueue));
        if(queue == NULL){
                puts("Memory allocation failed");
                exit(1);
        }

        puts("initial");
        init(queue, MAXSIZE);
        printf("length: %d\n", get_length(queue));

        puts("push 0-7");
        for(int i = 0; i < 8; i++){
                push(queue, i);
        }
        printf("length: %d\n", get_length(queue));
        
        puts("pop 0-5");
        for(int i = 0; i < 6; i++){
                printf("%d\n", pop(queue));
        }
        printf("length: %d\n", get_length(queue));
        printf("%d\n", get_top(queue));

        return 0;
}

