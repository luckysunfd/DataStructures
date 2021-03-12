#include "linked_stack.h"


void init_l(LinkedStackPtr lstack){
        lstack->length = 0;
        lstack->top = NULL;
} 

bool isEmpty_l(LinkedStackPtr lstack){
        if(lstack->top == NULL && lstack->length == 0){
                return true;
        }else{
                return false;
        }
}

/*
 * 链栈的入栈用链表的头插法插入的元素，因为栈只允许在其栈顶进行操作，这里用链表作为存储空间
 * 用链表头节点作为栈顶元素，那么栈顶指针应该指向栈顶元素也就是链表头节点
 * 在插入时，只需要用头插法插入新元素，然后更新栈顶元素指向就可以了
 *
 * */
void push_l(LinkedStackPtr lstack, DataType data){
        if(lstack == NULL){
                puts("请先初始化栈");
        }else{
                LinkedStackNodePtr node = (LinkedStackNodePtr)malloc(sizeof(LinkedStackNode));
                assert(node);
                memset(node, 0, sizeof(LinkedStackNode));
                node->data = data;
                
                node->next = lstack->top;      //新节点的next指针域指向栈顶元素
                lstack->top = node;            //栈顶指针指向新加入的节点
                lstack->length++;
        }
}

/*
 * 出栈，出栈务必要同时free释放其占用的堆空间，放置内存泄漏
 */ 
DataType pop_l(LinkedStackPtr lstack){
        if(lstack == NULL || isEmpty_l(lstack)){
                puts("栈为初始化或栈为空，请先初始化或入栈");
                return 0;
        }else{
                DataType pop_data = lstack->top->data;
                LinkedStackNodePtr next_node = lstack->top->next;   //临时变量，保存栈顶节点后面的那部分链表
                free(lstack->top);          //释放栈顶节点占用的堆空间
                lstack->top = next_node;    //赋值栈顶指针
                lstack->length--;
                return pop_data;            //返回弹出的值
        }
}

int get_length_l(LinkedStackPtr lstack){
        if(lstack == NULL){
                return 0;
        }else{
                return lstack->length;
        }
}

DataType get_top_l(LinkedStackPtr lstack){
        if(lstack == NULL){
                return 0;
        }else{
                return lstack->top->data;
        }
}

void destroy_l(LinkedStackPtr lstack){
        int count = 0;
        while(count < lstack->length){
                LinkedStackNodePtr next_node = lstack->top->next;
                free(lstack->top);
                lstack->top = next_node;
                lstack->length--;
                printf("l:%d\n", lstack->length);
        }
        printf("%p\n",lstack->top);
        printf("%d\n", lstack->length);

        lstack->top = NULL;
        lstack->length = 0;
}
