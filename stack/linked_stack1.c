//
//  main.c
//  linked_stack_demo
//
//  Created by sun on 2018/12/7.
//  Copyright © 2018 sun. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef int DataType;
typedef struct LinkedStackNode{
        DataType data;
        struct LinkedStackNode *next;
}LinkedStackNode, *LinkedStackNodePtr;

typedef struct LinkedStack{
        int cnt;
        LinkedStackNodePtr top;
}LinkedStack, *LinkedStackPtr;

//
void init(LinkedStackPtr s1){
        s1->top = NULL;
        s1->cnt = 0;
}

LinkedStackNodePtr create_node(DataType data){
        LinkedStackNodePtr node = (LinkedStackNodePtr)malloc(sizeof(LinkedStackNode));
        if(node == NULL){
                return NULL;
        }else{
                node->data = data;
                node->next = NULL;
                
                return node;
        }
}

void push(LinkedStackPtr s1, DataType data){
        LinkedStackNodePtr node = create_node(data);
        if(node == NULL){
                return ;
        }else{
                node->next = s1->top;
                s1->top = node;
                s1->cnt++;
        }
}

DataType pop(LinkedStackPtr s1){
        if(s1->top == NULL){
                return 0;
        }else{
                LinkedStackNodePtr temp = s1->top->next;
                DataType redata = s1->top->data;
                free(s1->top);
                s1->top = temp;
                s1->cnt--;
                
                return redata;
        }
}




int main(int argc, const char * argv[]) {
        // insert code here...
        printf("Hello, World!\n");
        
        LinkedStackPtr s1 = (LinkedStackPtr)malloc(sizeof(LinkedStack));
        init(s1);
        
        for(int i = 0; i < 5; i++){
                push(s1, i);
        }
        
        printf("%d\n", pop(s1));
        printf("%d\n", pop(s1));
        
        return 0;
}