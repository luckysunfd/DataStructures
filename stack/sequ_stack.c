/*  顺序栈的实现文件 */
#include "sequ_stack.h"


/*
 * 初始化栈
 *
 * 顺序栈利用了数组来存储节点，而根据栈的first in last out特性，只允许在栈的一端进行插入删除操作
 * 这个端点在顺序栈中被称为栈顶，顾名思义，也就是栈的顶部，这是逻辑上的结构
 * 物理上采用了数组用作存储节点，以及约束节点的边界，因为数组是线性连续内存空间，边界就俩头尾
 * 一是数组偏移为【0】的位置，而是数组偏移量最多的【array max】的位置
 * 其实选取哪一个作为顺序栈的栈定都是可以的
 * 出于实现简洁以及更符合心智思考的考量，在这里的实现采用的是偏移max的位置，选择偏移为0的实现相对来说优点绕
 */
void init_s(sequ_stackPtr sstack){
        /*
         * 数组的有效下表偏移量从数字0开始到所有可能的自然数，而由于仅仅是初始化顺序栈，
         * 那么，现在的栈顶指针是应该指向栈底的，反应到物理存储结构数组上就是不能是数组的有效偏移下表，
         * 所以应该初始化为一个负整数，而由于数组存储的必须是相同数据类型，偏移+1 即为下一个元素的位置，
         * 在第一个push入栈操作时，对栈顶指针自增++就可以了，如果选择的是其他副整数，不仅初次入栈时操作不优雅，
         * 后序的入栈也是需要跟初次入栈做为两种情况分别进行处理，出于简化操作的考量，
         * 这里对栈顶指针赋值为-1，入栈递增，出栈递减就可以,这赋值为-1，这在获取长度时也很有好处
         */

        sstack->top = -1;    
}

// 直接返回栈顶指针+1 就可以了
int get_length(sequ_stackPtr sstack){
        return sstack->top + 1;
}

/* 
 * 核心代码：先对栈顶指针递增，然后作为新的偏移下表，然后为这个数组元素赋值
 * 检查顺序栈是否已满，这是数组的固有缺点带来的必要检查，由于数组在定义时就必须确定下大小边界，所以要考量
 * 数组已满这种情况
 * 可以用bool作为返回值，已满返回false，未满且顺利入栈则返回true
 */
void push(sequ_stackPtr sstack, DataType data){
        if(is_full(sstack)){
                puts("顺序栈已满，不能执行入栈操作");
        }else{
                sstack->ele[++sstack->top] = data; //使用前置递增运算符
        }
}

DataType pop(sequ_stackPtr sstack){
        if(is_empty1(sstack)){
                puts("栈已空！不能执行出栈操作");
                return 0;
        }else{
                return sstack->ele[sstack->top--];  //使用后置递减运算符
        }
}
DataType get_top_element(sequ_stackPtr sstack){
        if(is_empty1(sstack)){
                return 0;
        }else{
                return sstack->ele[sstack->top];
        }
}

bool is_empty1(sequ_stackPtr sstack){
        if(sstack->top == -1){
                return true;
        }else{
                return false;
        }
}

bool is_full(sequ_stackPtr sstack){
        if(sstack->top == MAXSIZE - 1){
                return true;
        }else{
                return false;
        }
}
