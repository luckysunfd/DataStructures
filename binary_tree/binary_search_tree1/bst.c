#include "bst.h"


/*
ptr_bin_node stack1[1000] = {NULL};
unsigned int stack_top = -1;
unsigned int stack_cur_size = 0;
*/


ptr_bin_node Get_New_Node(ElemType data) {
    ptr_bin_node new_node = (ptr_bin_node)malloc(sizeof(bin_node_t));
    assert(new_node);

    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = data;

    return new_node;
}

void Create(bin_node_t **ppbst) {
    char c1;
    ElemType data;
    
    puts("输入#字符终止，其他字符继续");
    scanf("%c", &c1);
    
    if( c1 == '#' ) {
        return ;
    }
    
    puts("输入节点的值");
    scanf("%d", &data);

    (*ppbst) = Get_New_Node(data);
    Create(&((*ppbst)->left)); 
    Create(&((*ppbst)->right)); 

}

ptr_bin_node Insert_Node(ptr_bin_node bst, ElemType data) {
    if( bst == NULL ) {
        bst = Get_New_Node(data);
    }else if( data < bst->data ) {
        bst->left = Insert_Node(bst->left, data);
    }else{
        bst->right = Insert_Node(bst->right, data);
    } 
    return bst;
}


ptr_bin_node Find(ptr_bin_node bst, ElemType data) {
    /*
    ptr_bin_node stack1[1000] = {NULL};
    unsigned int stack_top = -1;
    unsigned int stack_cur_size = 0;
    */

    if( bst == NULL ) 
       return NULL;
    
    while( bst ) {
        /*
        stack1[++stack_top] = bst;
        stack_cur_size++;
        */
        switch(compare(bst, data)) {
            case 1:
                return bst;
            case 2:
                bst = bst->left;
                break;
            case 3:
                bst = bst->right;
                break;
        }
    }
    return NULL;
}

void In_Traversal(ptr_bin_node bst) {
    if( bst != NULL ) {
        In_Traversal(bst->left);
        printf("%d\n", bst->data);
        In_Traversal(bst->right);
    }
}


/*
 * 比较传入的节点的值与 要查找的值
 * 相等 返回 1
 * 小于 返回 2
 * 大于 返回 3
 *
 *
 */
unsigned int compare(ptr_bin_node bst, ElemType data) {
    if( bst->data == data ) {
        return 1;
    }else if( data < bst->data ) {
        return 2;
    }else{
        return 3;
    }
}

