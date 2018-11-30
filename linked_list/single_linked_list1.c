#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


typedef struct LinkedListNode{
        int data;
        struct LinkedListNode *next;
}LinkedListNode, *LinkedListNodePtr;


LinkedListNodePtr create_node(int data){
        LinkedListNodePtr node = (LinkedListNodePtr)malloc(sizeof(LinkedListNode));
        if(node == NULL){
                return NULL;
        }else{
                node->data = data;
                node->next = NULL;
        }
        return node;
}

LinkedListNodePtr create_linked(int num){
        LinkedListNodePtr head, node, tails;
        for(int i = 0; i < num; i++){
                if(head == NULL){
                        head = create_node(i);
                        tails = head;
                }else{
                        node = create_node(i);
                        tails->next = node;
                        tails = node;
                }
        }
        return head;
}

void visit_linked(LinkedListNodePtr head){
        if(head != NULL){
                printf("%d\n", head->data);
                visit_linked(head->next);
        }
}



int main(void){
        LinkedListNodePtr head = create_linked(10);
        visit_linked(head);

        return 0;
}
