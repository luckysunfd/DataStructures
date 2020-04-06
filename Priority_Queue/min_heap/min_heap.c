#include "min_heap.h"


ptr_min_heap Init(void) {
    ptr_min_heap pq1 = (ptr_min_heap)malloc(sizeof(min_heap_t));
    assert(pq1);

    pq1->cur_size = 0;
    pq1->capacity = MIN_HEAP_SIZE;
    memset(pq1->items, 0, sizeof(ElemType) * pq1->capacity);
    pq1->items[0] = INT_MIN;

    return pq1;
}

bool Full_(ptr_min_heap pq1) {
    if( pq1->cur_size == pq1->capacity ) {
        return true;
    }else{
        return false;
    }
}

bool Empty_(ptr_min_heap pq1) {
    if( pq1->cur_size == 0 ) {
        return true;
    }else{
        return false;
    }
}

void Enqueue(ptr_min_heap pq1, ElemType data) {
    int cur = ++pq1->cur_size;

    while( data < pq1->items[cur/2] ) {
        pq1->items[cur] = pq1->items[cur/2];
        cur /= 2;
    }
    pq1->items[cur] = data;
}

ElemType Dequeue(ptr_min_heap pq1) {
    int par = 1;
    int children = 2 * par;

    ElemType temp = pq1->items[pq1->cur_size--];
    ElemType min_v = pq1->items[1];

    while( children <= pq1->cur_size ) {
        if( children != pq1->cur_size && pq1->items[children] > pq1->items[children + 1] ) {
            children++;
        }
        if( temp < pq1->items[children] ){
            break;
        }
        pq1->items[par] = pq1->items[children];
        par = children;
        children = 2 * par;
    }
    pq1->items[par] = temp;

    return min_v;
}

ptr_min_heap Create_(ElemType *num, unsigned int num_size) {
    ptr_min_heap pq2 = Init();

    for(int i = 0; i < MIN_HEAP_SIZE; i++) {
        pq2->items[i+1] = num[i];
        pq2->cur_size++;
    }
    
    int par;
    int children;
    int j;
    ElemType temp;

    for( j = pq2->cur_size/2; j >=1; j-- ) {
        par = j;
        temp = pq2->items[j];

        while( 2 * par <= pq2->cur_size ) {
            children = par * 2;
            if( children != pq2->cur_size && pq2->items[children] > pq2->items[children+1] ) {
                children++;
            }
            if( temp < pq2->items[children] ) 
                break;

            pq2->items[par] = pq2->items[children];            
            par = children;
        }
        pq2->items[par] = temp;
    }

    return pq2;
}

unsigned int rand_rr(unsigned int a, unsigned int b) {
    return rand() % ((b - a + 1) + a);
}


void Destroy(ptr_min_heap pq1) {
    if( pq1 != NULL ) {
        free(pq1);
    }
}