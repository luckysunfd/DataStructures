#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>


typedef int ElemType;

typedef struct TWO_THREE_NODE {
    ElemType data_l;
    ElemType data_r;
    struct TWO_THREE_NODE *lchild;
    struct TWO_THREE_NODE *rchild;
    struct TWO_THREE_NODE *middle;
}two_three_node_t, *ptr_two_three;


int Get_Max(ptr_two_three cur_p, ElemType data);
int Get_Min(ptr_two_three cur_p, ElemType data);
int Get_Central(ptr_two_three cur_p, ElemType data);


unsigned int cmp(ptr_two_three cur, ElemType data);

ptr_two_three Find_Pos(ptr_two_three T, ElemType data, unsigned int *top, ptr_two_three *ancestor_table);

void Create_New_Root(two_three_node_t **T, ElemType data, ptr_two_three will_new_root_submiddle);

void Merge_In(two_three_node_t **cur_p, ElemType data, ptr_two_three q);

void Split(ptr_two_three cur_p, ElemType *ptr_data, two_three_node_t **q);

void Insert23(two_three_node_t **T, ElemType data);