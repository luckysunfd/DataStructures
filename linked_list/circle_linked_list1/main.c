/**
 * @author      : sun
 * @file        : main
 * @created     : Monday Dec 03, 2018 23:52:56 CST
 */

#include "clinked_list.h"




int main(void){
        cLinkedListPtr list1 = (cLinkedListPtr)malloc(sizeof(cLinkedList));
        if(list1 == NULL){
                puts("memory allocation error");
                exit(1);
        }

        puts("initial");
        init(list1);

        puts("尾插法");
        for(int i = 0; i < 10; i++){
                insert_node_2tails(list1, i);
        }

        puts("visit");
        visit(list1);

        puts("查找节点，查找节点data为9的节点并返回");
        if(find_node(list1, 9) != NULL){
                printf("%d\n", find_node(list1, 9)->data);
        }

        puts("find 999");
        find_node(list1, 999);

        puts("修改位置为5的节点数据为55555,1 ,11111,10,101010");
        alter_node(list1, 5, 55555);
        alter_node(list1, 1, 11111);
        alter_node(list1, 10, 101010);
        visit(list1);

        puts("删除链表头节点1");
        del_node(list1, 1);
        visit(list1);
        printf("length: %d\n", get_length(list1));

        puts("正在删除尾节点9");
        del_node(list1, 9);
        visit(list1);

        puts("删除链表位置5");
        del_node(list1, 5);
        visit(list1);

        puts("find 999");
        find_node(list1, 999);

        return 0;
}
