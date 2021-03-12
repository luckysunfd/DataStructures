/**
 * @author      : sun (lingganyang@gmail.com)
 * @file        : main
 * @created     : Wednesday Dec 05, 2018 17:55:18 CST
 */

#include "dlinked_list.h"


int main(void){
        DLinkedListPtr dlinked = (DLinkedListPtr)malloc(sizeof(DLinkedList));
        if(dlinked == NULL){
                puts("Memory allocation failed");
                exit(-1);
        }
        
        puts("初始化双向链表");
        init_dlinked(dlinked);
        
        puts("头插法插入节点");
        for(int i = 0; i < 10; i++){
                insert_nodeh(dlinked, i);
        }

        printf("linked length: %d\n", get_length(dlinked));

        puts("visit");
        visit_l(dlinked);
        
        puts("found 8");
        find_node(dlinked, 8);
        puts("found 1010");
        find_node(dlinked, 1010);

        puts("alter node 2 to 2222");
        alter_node(dlinked, 2, 2222);
        visit_l(dlinked);

        puts("del node 2");
        del_node(dlinked, 2);
        visit_l(dlinked);

        puts("销毁链表");
        destroy_dlinked(dlinked);
        printf("销毁完之后尝试读一下头节点，输出下地址看看，head %p  tails %p\n", dlinked->head, dlinked->tails);

        return 0;
}

