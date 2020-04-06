#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <time.h>


#define MIN_HEAP_SIZE (15)

typedef int ElemType;

typedef struct MIN_HEAP {
    ElemType items[MIN_HEAP_SIZE + 1];
    unsigned int cur_size;
    unsigned int capacity;
}min_heap_t, *ptr_min_heap;


ptr_min_heap Init(void);

bool Full_(ptr_min_heap pq1);

bool Empty_(ptr_min_heap pq1);

void Enqueue(ptr_min_heap pq1, ElemType data);

ElemType Dequeue(ptr_min_heap pq1);

ptr_min_heap Create_(ElemType *num, unsigned int num_size);

unsigned int rand_rr(unsigned int a, unsigned int b);

void Destroy(ptr_min_heap pq1);