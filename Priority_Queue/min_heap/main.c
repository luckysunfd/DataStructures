#include "min_heap.h"


int main(void) {
    ptr_min_heap pq1 = Init();
    puts("\n");

    ElemType num[MIN_HEAP_SIZE];
    ElemType a = rand_rr(20, 1000);

    for(int i = 0; i < MIN_HEAP_SIZE; i++) {
        num[i] = a;
        a = rand_rr(10, 2000);
    }

    free(pq1);

    ptr_min_heap pq2 = Create_(num, MIN_HEAP_SIZE);

    puts("\n");

    printf("cur size ; %d\n", pq2->cur_size);
    for(int i = 0; i <MIN_HEAP_SIZE; i++) {
        printf("%d -> ", Dequeue(pq2));
    }
    printf("cur size ; %d\n", pq2->cur_size);

    free(pq2);

    ptr_min_heap pq3 = Init();

    for(int i = 0; i < MIN_HEAP_SIZE; i++) {
        Enqueue(pq3, a);
        a =rand_rr(10, 2000);
    }

    for(int i = 0; i < MIN_HEAP_SIZE; i++) {
        printf("%d -> ", Dequeue(pq3));
    }

    free(pq3);
    puts("\n");
    
    return 0;
}