#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>


typedef int ElemType;

typedef struct AVL {
    ElemType data;
    struct AVL *left;
    struct AVL *right;
    unsigned int height;
}avl_t, *ptr_avl;


ptr_avl Get_New_Node(ElemType data);

unsigned int Get_Height(ptr_avl avl);

void Set_Height(ptr_avl avl);

/* four case */
// right-right 
ptr_avl Left_Rotation(ptr_avl avl);
// left-right
ptr_avl Left_Right_Rotation(ptr_avl avl);
// left-left
ptr_avl Right_Rotation(ptr_avl avl);
// right-left
ptr_avl Right_Left_Rotation(ptr_avl avl);

ptr_avl Get_Min_Node(ptr_avl avl);

int Get_BF(ptr_avl avl);

ptr_avl Insert_Node(ptr_avl avl, ElemType data);

ptr_avl Del_Node(ptr_avl avl, ElemType data);

void In_Traversal(ptr_avl avl);

