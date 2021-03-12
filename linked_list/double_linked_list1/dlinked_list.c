/**
 * @author      : sun 
 * @file        : dlinked_list
 * @created     : Wednesday Dec 05, 2018 12:50:50 CST
 */

#include "dlinked_list.h"




void init_dlinked(DLinkedListPtr dlinked){
        dlinked->head = NULL;
        dlinked->tails = NULL;
        dlinked->length = 0;
}

//生成节点
DLinkedListNodePtr create_node(DataType data){
        DLinkedListNodePtr node = (DLinkedListNodePtr)malloc(sizeof(DLinkedListNode));
        
        if(node == NULL){
                puts("Memory allocation failed");
                return NULL;
        }

        node->data = data;
        node->previous = NULL;
        node->next = NULL;

        return node;
}

//插入节点 -- 头插法
void insert_nodeh(DLinkedListPtr dlinked, DataType data){
        DLinkedListNodePtr node = create_node(data);
        if(node == NULL){
                puts("Memory allocation failed && insert error");
                return ;
        }
        
        /* 分两种情况插入
         *
         * 1. 链表是空链表时
         *    linked_list->head = null && linked_list->tails = null
         *    head->new_node, tails->new_node;
         *
         * 2. 链表不是空链表时
         *    头插法插入时，就是旧 新头节点之间的转换
         *    step1: 新节点next指向头节点
         *    step2: 旧头节点previous指向新节点
         *    step3；更新head 
         */
        if(dlinked->length == 0){
                dlinked->head  = node;
                dlinked->tails = node;
                dlinked->length++;
        }else{
                node->next = dlinked->head;
                dlinked->head->previous = node;
                dlinked->head = node;

                dlinked->length++;
        }
}

//尾插法
void insert_nodet(DLinkedListPtr dlinked, DataType data){
        DLinkedListNodePtr node = (DLinkedListNodePtr)malloc(sizeof(DLinkedListNode));
        if(node == NULL){
                puts("insert failed");
                return ;
        }

        if(dlinked->length == 0){
                dlinked->head = node;
                dlinked->tails = node;
                dlinked->length++;
        }
        else{
                node->previous = dlinked->tails;  
                dlinked->tails->next = node;
                dlinked->tails = node;

                dlinked->length++;
        }
}

//遍历
void visit_l(DLinkedListPtr dlinked){
        DLinkedListNodePtr current = dlinked->head;

        for(int i = 0; i < get_length(dlinked); i++){
                printf("%d\n", current->data);
                current = current->next;
        }
}

//查找节点，传入一个数据，返回第一个 数据相等的节点指针
DLinkedListNodePtr find_node(DLinkedListPtr dlinked, DataType fdata){
        if(is_empty(dlinked)){
                return NULL;
        }

        DLinkedListNodePtr current = dlinked->head;
        
        while(current->data != fdata && current->next != NULL){
                current = current->next;
        }
        if(current->data == fdata){
                puts("Found!");
                return current;
        }else{
                puts("Not Found!");
                return current;
        }
}

//删除节点,传入一个链表位置，然后删除它
void del_node(DLinkedListPtr dlinked, int position){
        if(is_empty(dlinked) || position < 1 || position > get_length(dlinked)){
                puts("Illegal position");
                return ;
        }else{
                int previous_num = 1;
                DLinkedListNodePtr current = dlinked->head;
                DLinkedListNodePtr want_del = NULL;
                
                while(previous_num != position - 1){
                        previous_num++;
                        current = current->next;
                }

                want_del = current->next;
                current->next = want_del->next;
                free(want_del);
                dlinked->length--;
        }
}

//修改节点
void alter_node(DLinkedListPtr dlinked, int position, DataType data){
        if(is_empty(dlinked) || position > get_length(dlinked) || position < 1){
                puts("Illegal position");
                return ;
        }else{
                int num = 1;
                DLinkedListNodePtr current = dlinked->head;
                while(num != position){
                        current = current->next;
                        num++;
                }
                current->data = data;
        }
}
//求链表长度
int get_length(DLinkedListPtr dlinked){
        if(is_empty(dlinked)){
                return 0;
        }else{
                return dlinked->length;
        }
}

//判空
bool is_empty(DLinkedListPtr dlinked){
        if(dlinked == NULL){
                puts("链表未初始化");
                return true;
        }else if(dlinked->length == 0){
                puts("链表为空");
                return true;
        }else{
                return false; 
        }
}
//销毁
void destroy_dlinked(DLinkedListPtr dlinked){
        if(is_empty(dlinked)){
                return ;
        }else{
                DLinkedListNodePtr current = dlinked->head;
                while(dlinked->length != 0){
                        dlinked->head = current->next;
                        free(current);
                        dlinked->length--;
                        current = dlinked->head;
                }
                dlinked->tails = NULL;
        }
}











