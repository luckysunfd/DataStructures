#include "two-three.h"


int main(void) {
    // ElemType st[3] = {0};
    ElemType data[] = { 50,30,20,10,5, 60,70,80,87,90,120 }; 
    
    ptr_two_three T = NULL;

    /* 试试冒泡排序
    st[0] = 10;
    st[1] = 4;
    st[2] = 6;

    Bubble_Sort2(st);
    */

    puts("50,30,20,10,5, 60,70,80,87,90,120");
    
    for(int i = 0; i < sizeof(data)/sizeof(data[0]); i++) {
        printf("%d->", data[i]);
        Insert23(&T, data[i]);
    }
    /*
    Insert23(&T, 50);
    Insert23(&T, 30);
    Insert23(&T, 20);
    Insert23(&T, 10);
    Insert23(&T, 5);
    Insert23(&T, 60);
    Insert23(&T, 70);
    Insert23(&T, 80);
    Insert23(&T, 87);
    Insert23(&T, 90);
    Insert23(&T, 120);
    */

    puts("-----------------");

    printf("2-3Tree Height: %d\n", Get_Height(T));

    return 0;
}
