#include "max_heap.h"


ptr_max_heap Init_1(void) {
    ptr_max_heap new_pq1 = (ptr_max_heap)malloc(sizeof(max_heap_t));
    assert(new_pq1);

    new_pq1->cur_size = 0;
    new_pq1->capacity = MAX_HEAP_SIZE;
    memset(new_pq1->items, 0, sizeof(ElemType) * (MAX_HEAP_SIZE+1));
    new_pq1->items[0] = INT_MAX;

    return new_pq1;
}

bool Full_1(ptr_max_heap pq1) {
    if( pq1->cur_size == pq1->capacity )
        return true;
    else
        return false;    
}

bool Empty_1(ptr_max_heap pq1) {
    if( pq1->cur_size == 0 )
        return true;
    else 
        return false;
}

void Enqueue(ptr_max_heap pq1, ElemType data) {
    int cur_index = ++pq1->cur_size;

    while( data > pq1->items[cur_index/2] ) {
        pq1->items[cur_index] = pq1->items[cur_index/2];
        cur_index /= 2;
    }
    pq1->items[cur_index] = data;
}

ElemType Dequeue(ptr_max_heap pq1) {
    int par = 1;
    int children = par * 2;

    ElemType temp = pq1->items[pq1->cur_size--];
    ElemType max_v = pq1->items[1];

    while( children <= pq1->cur_size ) {
        if( children != pq1->cur_size && pq1->items[children] < pq1->items[children + 1] ) {
            children++;
        }

        if( temp > pq1->items[children] )
            break;

        pq1->items[par] = pq1->items[children];

        par = children;
        children = par * 2;
    }
    pq1->items[par] = temp;

    return max_v;
}

ptr_max_heap Create_1(ElemType *num);

void Destroy(ptr_max_heap pq1) {
    if( pq1 != NULL ) {
        free(pq1);
    }
}