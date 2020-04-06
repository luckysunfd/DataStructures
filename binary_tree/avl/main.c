#include "avl.h"
#include <time.h>

unsigned int rand_rr(unsigned int a, unsigned int b) {
    return rand() % ( (b - a + 1) + a);
}




int main(void) {
    ptr_avl avl = NULL;
    ElemType a = rand_rr(30, 800);

    for( int i = 0; i < 100; i++ ) {
        avl = Insert_Node(avl, a);
        a = rand_rr(30, 1900);
    }

    puts("In traversal");
    avl = Insert_Node(avl, 99);
    In_Traversal(avl);

    avl = Del_Node(avl, 99);
    In_Traversal(avl);

    puts("-----------------");
    printf("\ncount node: %d\n", Count_Node(avl));
    a = rand_rr(30, 1200);
    for( int i = 0; i < 3000; i++ ) {
        avl = Del_Node(avl, a);
        a = rand_rr(10, 1500);
    }
    In_Traversal(avl);
    printf("\ncount node: %d\n", Count_Node(avl));

    puts("----------------");

    return 0;
}