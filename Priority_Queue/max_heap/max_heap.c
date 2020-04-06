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

ptr_max_heap Create_1(ElemType *num, unsigned int num_size) {
    ptr_max_heap pq2 = Init_1();

    for(int i = 0; i < num_size; i++) {
        if( Full_1(pq2) ) {
            break;
        }
        pq2->items[i+1] = num[i];
        pq2->cur_size++;
    }

    int j;
    int par;
    int children;
    ElemType temp;

    for( j = pq2->cur_size/2; j >= 1; j--) {
        par = j;
        temp = pq2->items[j];

        while( 2 * par <= pq2->cur_size ) {
            children = 2 * par;
            if( children != pq2->cur_size && pq2->items[children] < pq2->items[children+1] ) {
                children++;
            }
            if( temp > pq2->items[children] )
                break;
            pq2->items[par] = pq2->items[children];
            par = children;
        }
        pq2->items[par] = temp;
    }

    return pq2;
}

void Destroy(ptr_max_heap pq1) {
    if( pq1 != NULL ) {
        free(pq1);
    }
}