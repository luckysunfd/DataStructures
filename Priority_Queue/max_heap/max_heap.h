#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <limits.h>


#define MAX_HEAP_SIZE (15)

typedef int ElemType;

typedef struct MAX_HEAP {
    ElemType items[MAX_HEAP_SIZE + 1];
    unsigned int cur_size;
    unsigned int capacity;
}max_heap_t, *ptr_max_heap;


ptr_max_heap Init_1(void);

bool Full_1(ptr_max_heap pq1);

bool Empty_1(ptr_max_heap pq1);

void Enqueue(ptr_max_heap pq1, ElemType data);

ElemType Dequeue(ptr_max_heap pq1);

ptr_max_heap Create_1(ElemType *num, unsigned int num_size);

void Destroy(ptr_max_heap pq1);