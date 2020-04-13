#include "array_list.h"


// 初始化动态数组
ptr_arrlist Init_AL(ptr_arrlist list) {
    if( list == NULL ) {
        list = (ptr_arrlist)malloc(sizeof(arrlist));
        assert(list);

        list->arr = (ElemType *)malloc(sizeof(ElemType) * DEFAULT_ARRAY_SIZE);
        assert(list->arr);
        memset(list->arr, 0, sizeof(ElemType) * DEFAULT_ARRAY_SIZE);
        list->cur = -1;
        list->capacity = DEFAULT_ARRAY_SIZE;
    }

    return list;
}

// 插入 
void Insert_At(ptr_arrlist list, ElemType data, unsigned int pos) {
    if( Full_AL(list) ) {
        Expand_AL(list);
    }

    if( pos >= list->capacity ) {
        puts("非法位置");
        return ;
    }

    if( pos == 0 ) {
        list->arr[pos] = data; 
    }else{
        for(int i = list->cur; i >= pos; i--) {
            list->arr[i+1] = list->arr[i]; 
        }
        list->arr[pos] = data;
    }

    list->cur++;
}

// 满？
bool Full_AL(ptr_arrlist list) {
    if( list != NULL && list->cur+1 != list->capacity ) {
        return false;
    }else{
        return true;
    }
}

// 空？
bool Empty_AL(ptr_arrlist list) {
    if( list == NULL || list->cur == -1 ) {
        return true;
    }else{
        return false;
    }
}

// 扩容
void Expand_AL(ptr_arrlist list) {
    ElemType *oldData = list->arr;  // 把旧空间暂存起来，不然一会儿该无家可归了
    
    list->arr = (ElemType *)malloc(sizeof(ElemType) * 2 * list->capacity); // 当前动态数组最大容量的2倍扩容
    assert(list->arr);

    // 把旧的移动到新的里面去， memcpy
    memcpy(list->arr, oldData, sizeof(ElemType) * list->capacity);
    list->capacity = 2 * list->capacity;

    free(oldData);
}

// 置空
void Clear_AL(ptr_arrlist list) {
    list->cur = -1;
}

// 释放
void Free_AL(ptr_arrlist list) {
    if( list != NULL ) {
        free(list->arr);
        free(list);
    }
}

// 获取自定位置上的元素
ElemType Get_At(ptr_arrlist list, unsigned int pos) {
    if( pos <= list->cur ) {
        return list->arr[pos];
    }
}


