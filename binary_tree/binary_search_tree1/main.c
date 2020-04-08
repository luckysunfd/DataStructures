#include "bst.h"


int main(void) {
    ptr_bin_node T = NULL;
    
    T = Get_New_Node(40);
    T->left = Get_New_Node(30);
    T->right = Get_New_Node(50);
    
    T->left->left = Get_New_Node(20);
    T->left->right = NULL;

    T->right->left = Get_New_Node(45);
    T->right->right = Get_New_Node(60);

    In_Traversal(T);

    puts("search 70");
    if( Find(T, 70) )
        puts("FIND");
    else
        puts("NOT Found");
    
    puts("search 45");
    if( Find(T, 45) )
        puts("find");
    else
        puts("not find");


    return 0;
}
