#include "seq_queue.h"


int main(void){
        SeqQueuePtr sq1 = (SeqQueuePtr)malloc(sizeof(SeqQueue));
        if(sq1 == NULL){
                puts("Memory allocation error");
                return 1;
        } 

        puts("Initial queue");
        init_seq_queue(sq1, MAXSIZE);

        puts("enter queue");
        for(int i = 0; i < MAXSIZE; i++){
                enter_seq_queue(sq1, i);
        }

        puts("delete queue");
        printf("%d\n", delete_seq_queue(sq1));
        printf("%d\n", delete_seq_queue(sq1));
        printf("%d\n", delete_seq_queue(sq1));
        printf("%d\n", delete_seq_queue(sq1));
        printf("%d\n", delete_seq_queue(sq1));

        return 0;
}