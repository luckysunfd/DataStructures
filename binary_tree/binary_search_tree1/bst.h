#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int ElemType;

typedef struct BIN_NODE {
    ElemType data;
    struct BIN_NODE *left;
    struct BIN_NODE *right;
}bin_node_t, *ptr_bin_node;


ptr_bin_node Get_New_Node(ElemType data);

void Create(bin_node_t **ppbst);

ptr_bin_node Insert_Node(ptr_bin_node bst, ElemType data);

ptr_bin_node Find(ptr_bin_node bst, ElemType data, ptr_bin_node *stack, unsigned int *top, unsigned int *cur_size);

void In_Traversal(ptr_bin_node bst);

unsigned int compare(ptr_bin_node bst, ElemType data);

ElemType Get_Min_V(ptr_bin_node bst);

ptr_bin_node Del_Node(ptr_bin_node bst, ElemType data);
