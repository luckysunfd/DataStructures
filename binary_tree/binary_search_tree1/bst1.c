/**
 * @file        : bst1
 * @created     : Wednesday Dec 05, 2018 23:30:45 CST
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef int DataType;
typedef struct BinarySearchTreeNode{
        DataType data;
        struct BinarySearchTreeNode *left;
        struct BinarySearchTreeNode *right;
}BinarySearchTreeNode, *BinarySearchTreeNodePtr;


BinarySearchTreeNodePtr create_node(DataType data){
        BinarySearchTreeNodePtr node = (BinarySearchTreeNodePtr)malloc(sizeof(BinarySearchTreeNode));
        if(node == NULL){
                puts("Memory allocation failed");
                return NULL;
        }else{
                node->data = data;
                node->left = NULL;
                node->right = NULL;
        }

        return node;
}

BinarySearchTreeNodePtr insert_node(BinarySearchTreeNodePtr root, DataType data){
        if(root == NULL){
                root = create_node(data);
        }else if(root->data > data){
                root->left = insert_node(root->left, data);
        }else{
                root->right = insert_node(root->right, data);
        }
        return root;
}

void preorder_visit(BinarySearchTreeNodePtr bst){
        if(bst != NULL){
                printf("%d\n", bst->data);
                preorder_visit(bst->left);
                preorder_visit(bst->right);
        }
}

/*
int main(void){
        BinarySearchTreeNodePtr bst = NULL;

        bst = insert_node(bst, 10);
        bst = insert_node(bst, 3);
        bst = insert_node(bst, 9);
        bst = insert_node(bst, 11);
        bst = insert_node(bst, 6);
        
        puts("pre order visit");
        preorder_visit(bst);

        return 0;
}
*/