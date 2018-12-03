/**
 * @author      : sun (lingganyang@gmail.com)
 * @file        : clinked_list
 * @created     : Monday Dec 03, 2018 22:05:31 CST
 */

#include "clinked_list.h"

//初始化
void init(cLinkedListPtr clinked_list){
        clinked_list->head = NULL;
        clinked_list->tails = NULL;
        clinked_list->length = 0;
}
//创建链表节点
cLinkedListNodePtr create_node(DataType data){
        cLinkedListNodePtr node = (cLinkedListNodePtr)malloc(sizeof(cLinkedListNode));
        if(node == NULL){
                puts("Memory allocation error");
                return NULL;
        }

        node->data = data;
        node->next = NULL;

        return node;
}
//添加节点,尾插法
void insert_node_2tails(cLinkedListPtr clinked_list, DataType data){
        cLinkedListNodePtr node = create_node(data);
        if(node == NULL){
                return ;
        }
        else if(clinked_list->head == NULL && clinked_list->tails == NULL){
                clinked_list->head = node;
                clinked_list->tails = node;
                clinked_list->tails->next = clinked_list->head;

                clinked_list->length++;
        }else{
                node->next = clinked_list->tails->next;   //新节点next指向表尾next指向的地方，即表头
                clinked_list->tails->next = node;       //将新节点添加到链表 尾处
                clinked_list->tails = node;            //更新链尾tails
                
                clinked_list->length++;
        }
}
//头插法添加节点
void insert_node_2head(cLinkedListPtr clinked_list, DataType data){
        cLinkedListNodePtr node = create_node(data);
        if(node == NULL){
                return ;
        }else{
                if(clinked_list->head == NULL && clinked_list->tails == NULL){
                        clinked_list->head = node;
                        clinked_list->tails = node;
                        clinked_list->tails->next = clinked_list->head;
                        
                        clinked_list->length++;
                }else{
                        node->next = clinked_list->head->next; //新节点指向头部节点next指向的地方
                        clinked_list->head = node;      //更新头部节点为新节点
                        clinked_list->tails->next = clinked_list->head;   //更新尾部节点next指向新节点，即表头

                        clinked_list->length++;
                }
        }
}

int get_length(cLinkedListPtr clinked_list){
        return clinked_list->length;
}

void visit(cLinkedListPtr clinked_list){
        cLinkedListNodePtr current = clinked_list->head;
        for(int i = 0; i < get_length(clinked_list); i++){
                printf("%d %d\n", i, current->data);
                current = current->next;
        }
}

cLinkedListNodePtr find_node(cLinkedListPtr clinked_list, DataType fdata){
        cLinkedListNodePtr current = clinked_list->head;
        int num = clinked_list->length - 1;

        while(current->data != fdata && num != 0){
                current = current->next;
                num--;
        }

        if(current->data == fdata){
                puts("Found!");
                return current;
        }else{
                puts("Not Found!");
                return NULL;
        }
}


void alter_node(cLinkedListPtr clinked_list, int position, DataType data){
        if(position > clinked_list->length){
                puts("非法位置");
        }else{
                cLinkedListNodePtr current = clinked_list->head;   
                int num = 1;
                while(num != position){
                        current = current->next;
                        num++;
                }
                current->data = data;
        }
}

bool is_empty(cLinkedListPtr clinked_list){
        if(clinked_list->head == NULL && clinked_list->tails == NULL){
                return true;
        }else{
                return false;
        }
}

void del_node(cLinkedListPtr clinked_list, int position){
        //todo
}
