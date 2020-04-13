#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>


#define DEFAULT_ARRAY_SIZE 10

typedef int ElemType;

typedef struct ARRAY_LIST {
    int cur;
    unsigned int capacity;
    ElemType *arr;
}arrlist, *ptr_arrlist;


// 初始化动态数组
ptr_arrlist Init_AL(ptr_arrlist list);

// 插入
// 支持任意位置的插入
// 仅允许在指定范围之内插入，【0-cur】给定的值超出范围，则报错
// 如果恰好满了，旧扩容
void Insert_At(ptr_arrlist list, ElemType data, unsigned int pos);

// 获取指定位置的元素
ElemType Get_At(ptr_arrlist list, unsigned int pos);

// 满？
bool Full_AL(ptr_arrlist list);

// 空？
bool Empty_AL(ptr_arrlist list);

// 扩容
void Expand_AL(ptr_arrlist list);

// 置空
void Clear_AL(ptr_arrlist list);

// 释放
void Free_AL(ptr_arrlist list);