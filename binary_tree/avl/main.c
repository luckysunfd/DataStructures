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
    In_Traversal(avl);

    return 0;
}