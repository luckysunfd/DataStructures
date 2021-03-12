// 栈 操作演示程序

#include "sequ_stack.h"
#include "linked_stack.h"
#include <assert.h> //debug mode only
#include <string.h> //memset function

int main(void){
        puts("创建一个顺序栈，这里在堆上为栈结构申请一块存储空间");
        sequ_stackPtr sstack1 = (sequ_stackPtr)malloc(sizeof(sequ_stack));
        assert(sstack1);
        memset(sstack1, 0, sizeof(sequ_stack));
        
        puts("initial sequ_stack...");
        init_s(sstack1);
        puts("initial success");

        printf("current length:%d\n", get_length(sstack1));
        if(is_empty1(sstack1)){
                puts("empty sequ_stack");
        }

        if(is_full(sstack1)){
                puts("full sequ_stack");
        }
        puts("push!");
        for(int i = 200; i < 300; i++){
                push(sstack1, i);
        }
        puts("push end");
        
        printf("current length:%d\n", get_length(sstack1));
        printf("current top element:%d\n", get_top_element(sstack1));
        if(is_empty1(sstack1)){
                puts("empty sequ_stack");
        }

        if(is_full(sstack1)){
                puts("full sequ_stack");
        }

        printf("pop: %d\n", pop(sstack1));
        printf("current length:%d\n", get_length(sstack1));
        printf("current top element:%d\n", get_top_element(sstack1));

        puts("-------------linked stack demo----------------");
        LinkedStackPtr lstack = (LinkedStackPtr)malloc(sizeof(LinkedStack));
        assert(lstack);
        memset(lstack, 0, sizeof(LinkedStack));
        //初始化栈
        init_l(lstack);
        printf("current linked stack length:%d\n", get_length_l(lstack));
        printf("pop: %d\n", pop_l(lstack));
        if(isEmpty_l(lstack)){
                puts("empty linked stack");
        }
        puts("push start");
        for(int i = 0; i < 10; i++){
                push_l(lstack, i);
        }
        puts("push end");

        printf("pop:%d\n", pop_l(lstack));
        printf("pop:%d\n", pop_l(lstack));
        printf("current length:%d\n", get_length_l(lstack));
        printf("current top:%d\n", get_top_l(lstack));

        destroy_l(lstack);


        return 0;
}
