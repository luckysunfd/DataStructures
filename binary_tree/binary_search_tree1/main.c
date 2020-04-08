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

    puts("------Start In Traversal-----");
    In_Traversal(T);
    puts("------In Traversal end-------");

    ptr_bin_node stack[1000] = { NULL };
    unsigned int top = -1;
    unsigned int cur_size = 0;

    puts("search 70");
    if( Find(T, 70, stack, &top, &cur_size) )
        puts("FIND");
    else
        puts("NOT Found");
    
    puts("输出栈内容");
    for( int i = 0; i < cur_size; i++ ) {
        printf("%d->", stack[i]->data);
    }
    puts("\n");
    
    top = -1;
    cur_size = 0;

    puts("search 45");
    if( Find(T, 45, stack, &top, &cur_size) ) 
        puts("find");
    else
        puts("not find");

    puts("输出栈内容");
    for( int i = 0; i < cur_size; i++ ) {
        printf("%d->", stack[i]->data);
    }
    puts("\n");


    return 0;
}
