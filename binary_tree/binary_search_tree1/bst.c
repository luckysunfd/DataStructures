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


ptr_bin_node Find(ptr_bin_node bst, ElemType data, ptr_bin_node *stack, unsigned int *top, unsigned int *cur_size) {
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
        stack[++(*top)] = bst;
        (*cur_size)++;
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

/* 获取给定bst中的最小节点的值 */
ElemType Get_Min_V(ptr_bin_node bst) {
    while(bst->left != NULL) {
        bst = bst->left;
    }

    return bst->data;
}

/* 从搜索二叉树中删除一个给定值节点
 * 分两种情况：
 *   1. 如果被删除的节点是叶子节点，直接删除即可
 *   2. 如果被删除的节点不是叶子节点，就将其转换成对叶子节点的删除，还有就是如果这个非叶子节点拥有一个节点、两个节点的处理情况是不同的
 *
 *   针对2，如果一个非叶子节点拥有一个节点，直接将节点释放，并把它的子节点传递给释放掉的姐弟啊你的父节点即可
 *          如果一个非叶子节点拥有两个节点，那就从其右子树中找到最小值的节点，用它替换掉被删除的节点值，然后删除这个最小节点就好了
 *
 *   递归方法
 */
ptr_bin_node Del_Node(ptr_bin_node bst, ElemType data) {
    if( bst == NULL ) {
        return NULL;
    }

    if( data < bst->data ) {
        bst->left = Del_Node(bst->left, data);
    }else if( data > bst->data ) {
        bst->right = Del_Node(bst->right, data);
    }else{
        /* same as data */
        ptr_bin_node temp = NULL;
        //if only one child
        if( bst->left == NULL ) {
            temp = bst->right;
            free(bst);
            return temp;
        }
        if( bst->right == NULL ) {
            temp = bst->left;
            free(bst);
            return temp;
        }
        //if two child
        ElemType min_data = Get_Min_V(bst->right);
        bst->data = min_data;
        bst->right = Del_Node(bst->right, min_data);
    }

    return bst;
}
