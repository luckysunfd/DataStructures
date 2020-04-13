#include "array_list.h"


int main(void) {
    ptr_arrlist list = NULL;
    list = Init_AL(list);

    Insert_At(list, 10, 0);
    Insert_At(list, 30, 1);
    Insert_At(list, 90, 2);
    Insert_At(list, 100, 3);
    Insert_At(list, 180, 4);
    Insert_At(list, 104, 5);
    Insert_At(list, 109, 6);
    Insert_At(list, 101, 7);
    Insert_At(list, 150, 8);
    Insert_At(list, 190, 9);
    Insert_At(list, 130, 10);

    puts("---------");
    printf("Index 8 : %d\n", Get_At(list, 8));

    Insert_At(list, 200, 10);
    Insert_At(list, 3333333, 3);

    puts("-------");

    Free_AL(list);

    return 0;
}