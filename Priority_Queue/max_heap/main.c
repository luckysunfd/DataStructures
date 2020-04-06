#include "max_heap.h"
#include <time.h>

unsigned int rand_rr(unsigned int a, unsigned int b) {
    return rand() % ( (b - a + 1) + a );
}


int main(void) {
    ptr_max_heap pq1 = Init_1();
    ElemType a = rand_rr(30, 2000);

    for(int i = 0; i < 30; i++) {
        if( Full_1(pq1) ) {
            puts("\n憋怼了，满了\n");
            break;
        }
        Enqueue(pq1, a);
        a = rand_rr(50, 1500);
    }

    for( int i = 0; i < 30; i++ ) {
        if( Empty_1(pq1) ) {
            puts("\n憋怼了，空了\n");
            break;
        }

        printf("%d -> ", Dequeue(pq1));
    }

    puts("\n");

    ElemType num[MAX_HEAP_SIZE];

    for( int i = 0; i < MAX_HEAP_SIZE; i++) {
        num[i] = a;
        a = rand_rr(30 ,5000);
    }

    ptr_max_heap pq2 = Create_1(num, MAX_HEAP_SIZE);

    printf("cur_size %d\n", pq2->cur_size);
    for( int i = 0; i < MAX_HEAP_SIZE; i++) {
        printf("%d -> ", Dequeue(pq2));
    }
    puts("\n");
    printf("cur_size %d\n", pq2->cur_size);



    return 0;
}