/**
 * @author      : sun (lingganyang@gmail.com)
 * @file        : main
 * @created     : Saturday Dec 01, 2018 23:22:19 CST
 */

#include "linked_queue.h"


int main(void){
        LinkedQueuePtr lq1 = (LinkedQueuePtr)malloc(sizeof(LinkedQueue));
        if(lq1 == NULL){
                puts("Memory allocation error");
                return 1;
        }else{
                init_linked_queue(lq1);

                for(int i = 0; i < 10; i++){
                        enter_queue(lq1, i);
                }
                puts("----------------");
                printf("current queue length: %d\n", get_length_linked_queue(lq1));

                printf("%d\n", delete_queue(lq1));
                printf("%d\n", delete_queue(lq1));
                printf("%d\n", delete_queue(lq1));
                printf("%d\n", delete_queue(lq1));
                
                printf("current queue length: %d\n", get_length_linked_queue(lq1));

                return 0;
        }
}

