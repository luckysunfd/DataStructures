#include "linked_queue.h"


int main(void){
        LinkedQueuePtr lq1 = (LinkedQueuePtr)malloc(sizeof(LinkedQueue));
        if(lq1 == NULL){
                puts("Memory allocation failed");
                exit(-1);
        }

        puts("initial");
        init(lq1);

        puts("入队");
        for(int i = 0; i < 10; i++){
                enter_queue(lq1, i+10);
        }

        printf("length:%d\n", get_length(lq1));

        puts("出队2次");
        delete_queue(lq1);
        delete_queue(lq1);
        printf("%d\n", get_length(lq1));

        for(int i = 0; i < 8; i++){
                puts("del");
                delete_queue(lq1);
        }
        printf("%d\n", get_length(lq1));
        puts("出队");
        delete_queue(lq1);

        printf("length: %d\n", get_length(lq1));

        return 0;
}