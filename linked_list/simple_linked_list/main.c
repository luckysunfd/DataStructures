#include "linked_list.h"


int main(void){
       
        linked_list_ptr linked1 = NULL;
        
        puts("initial linked");
        linked1 = init_1(linked1);
        
        puts("insertion");
        for(int i = 0; i < 10; i++){
                printf("尾插法插入节点%d\n", i);
                insert_t(linked1, i);
        }
        puts("insertion end");

        puts("get length:");
        printf("%d\n", get_length_1(linked1));

        puts("Visit");
        print_linked(linked1);

        puts("remove position 5 node");
        puts("start remove");
        remove_node_1(linked1, 5);
        puts("remove end");
        print_linked(linked1);
        puts("remove node position 9");
        remove_node_1(linked1, 9);
        printf("-------------------------linked1 length:%d\n", get_length_1(linked1));
        printf("-------------------------tails data:%d\n", linked1->tails->data);

        puts("add node 3, 9, 20, 10, 12, 13");
        add_node_1(linked1, 3, 3333);
        print_linked(linked1);
        add_node_1(linked1, 9, 9999);
        print_linked(linked1);
        add_node_1(linked1, 20, 202020);
        add_node_1(linked1, 10, 101000);
        printf("get tails node data:%d\n", linked1->tails->data);
        add_node_1(linked1, 12, 121212);
        printf("get tails node data:%d\n", linked1->tails->data);
        add_node_1(linked1, 13, 131313);
        printf("get tails node data:%d\n", linked1->tails->data);
        print_linked(linked1);
        puts(" ");
        printf("current length%d\n", get_length_1(linked1));
        
        alter_node_data_1(linked1, 2, 2222);
        puts("find data 9999");
        linked_node_ptr fn = find_node_data_1(linked1, 9999);
        printf("node addr:%p v:%d\n", fn, fn->data);
        puts("find data 1111");
        
        linked_node_ptr fn1 = find_node_data_1(linked1, 1111);

        printf("%d\n", get_length_1(linked1));
        
        puts("destroy linked");
        destroy_linked_1(linked1);

        printf("%d\n", get_length_1(linked1));
        printf("linked list head tails ptr:%p\n%p\n", linked1->head, linked1->tails);
        //printf("%d\n", linked1->head->data);

        return 0;
}
