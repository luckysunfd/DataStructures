#include "two-three.h"


/* 
 *  用冒泡排序获取最大值，最小值，以及中间值 
 *  Get_Max 返回最大值
 *  Get_Min 返回最小值
 *  Get_Central 返回中间值
 *  
 */
int Get_Max(ptr_two_three cur_p, ElemType data) {
    ElemType st[3] = {0};
    st[0] = data;
    st[1] = cur_p->data_l;
    st[2] = cur_p->data_r;

    for(int i = 0; i < 3-1; i++) {
        for(int j = 0; j < 3-i-1; j++) {
            if( st[j] > st[j+1] ) {
                    ElemType temp = st[j];
                    st[j] = st[j+1];
                    st[j+1] = temp;
            }
        }
    }

    return st[2];
}

int Get_Min(ptr_two_three cur_p, ElemType data) {
    ElemType st[3] = {0};
    st[0] = data;
    st[1] = cur_p->data_l;
    st[2] = cur_p->data_r;

    for(int i = 0; i < 3-1; i++) {
        for(int j = 0; j < 3-i-1; j++) {
            if( st[j] > st[j+1] ) {
                    ElemType temp = st[j];
                    st[j] = st[j+1];
                    st[j+1] = temp;
            }
        }
    }

    return st[0];
}

int Get_Median(ptr_two_three cur_p, ElemType data) {
    ElemType st[3];
    st[0] = data;
    st[1] = cur_p->data_l;
    st[2] = cur_p->data_r;
    // BubbleSort
    for(int i = 0; i < 3-1; i++) {
        for(int j = 0; j < 3-i-1; j++) {
            if( st[j] > st[j+1] ) {
                    ElemType temp = st[j];
                    st[j] = st[j+1];
                    st[j+1] = temp;
            }
        }
    }

    return st[1];
}

/*
 *
 *          用于比较当前节点与欲插入值
 * 1. 如果 要插入的值 等于 当前节点 的值， 返回 1
 * 2. 如果 要插入的值 小于 当前节点 的值， 返回 2
 * 3. 如果 要插入的值 大于 当前节点 的值， 返回 3
 * 4. 如果 要插入的值 大于左，小于右，则   返回 4
 * 
 */
unsigned int cmp(ptr_two_three cur, ElemType data) {
    if( data == cur->data_l || data == cur->data_r ) {
        return 1;
    }
    if( data < cur->data_l ) {
        return 2;
    }
    if( data > cur->data_r ) {
        return 3;
    }else{
        return 4;
    }
}

/*
 * 查找合适的插入位置：
 * 1. 如果返回1， 那就是在树中找到了某个节点等于要插入的值，那就返回 null
 * 2. 如果返回2， 那就往左走
 * 3. 如果返回3， 那就往右走
 * 4. 如果返回4， 那就往中间走
 * 
 * 这样一层层找下去，直到遇到叶子节点或者返回null，并在这个过程中，每下一层就入栈
 * 
*/
ptr_two_three Find_Pos(ptr_two_three T, ElemType data, unsigned int *top, ptr_two_three *ancestor_table) {
    *top = -1;

    while(T) {
        ancestor_table[++(*top)] = T;

        switch( cmp(T, data) ) {
            case 1:
                return NULL;
            case 2:
                T = T->lchild;
                break;
            case 3:
                T = T->rchild;
                break;
            case 4:
                T = T->middle;
                break;
        }
    }

    return ancestor_table[(*top)--];  // 叶子节点最后也是入栈在栈顶的，因为要返回叶子节点，所以弹栈顶取出栈顶元素
}


/*
 * 创建新的根节点，包括三个参数
 * 1. 第一个参数是指向根节点的一个二级指针，因为要在这个过程中修改树根节点的指向，而这个原根节点则将成为新根节点的左节点
 * 2. 第二个参数是要插入的值
 * 3. 第三个参数则是将成为 中间子树 的指针
 * 
 * 执行完该函数后， T指向新的根节点地址，旧T 指向的地址 则将成为新根T 的左节点，第三个参数则成为新T 的 中间节点
 * 
 *  NOTE: 2-3树中，节点只有两种，2节点，三节点，且2节点如果不是叶子节点，那就有两个（left， middle）有效子节点,
 *        
*/
void Create_New_Root(two_three_node_t **T, ElemType data, ptr_two_three will_new_root_submiddle) {
    // 保存原 根节点
    ptr_two_three temp_will_new_root_lchild = (*T);
    
    // 新生成个根节点，并初始化、赋值
    *T = (ptr_two_three)malloc(sizeof(two_three_node_t));
    (*T)->data_l = data;  
    (*T)->data_r = INT_MAX;
    (*T)->lchild = temp_will_new_root_lchild;
    (*T)->middle = will_new_root_submiddle;
    (*T)->rchild = NULL;
}


/*
 * 合并值到2节点
 * 
 * 三个参数：
 * 1. 当前节点
 * 2. 要插入的值
 * 3. 放置子树q至融合插入值的右侧
 * 
 * 概要：
 * 2-3树的值插入除根节点外，都是先找到合适的插入叶子位置，然后判断这个叶子是2节点还是三节点
 * 如果是2节点，那么就融合进去
 * 融合进去也需要遵循一定的规则，不能简单的放进去就不管了，需要调整的
 * 
 * 2节点拥有一个使用的数据域，两个使用的指针域 -> 变换成一个3节点 -- 即把2个数据域， 三个指针域全部用起来
 * 也就是说，在这一过程中，需要对2数据域，3指针域进行操作调整
 * 
 * 1.  如果要 插入的值 小于 当前节点中 原有的值（data_l）， 将待插入的值放在data_l中， 原有的值 右移 到data_r, 这是 数据域的调整
 *     指针域则： q则变成middle， 原middle 右移至 rchild  
 * 2.  如果要 插入的值 大于 当前节点中 原有的值(data_l), 将待插入的值直接放在data_r中， q则放在right中
 * 
 * 
*/
void Merge_In(two_three_node_t **cur_p, ElemType data, ptr_two_three q) {
    if( data < (*cur_p)->data_l ) {
        (*cur_p)->data_r = (*cur_p)->data_l;
        (*cur_p)->data_l = data;
        (*cur_p)->rchild = (*cur_p)->middle;
        (*cur_p)->middle = q;
    }else{
        (*cur_p)->data_r = data;
        (*cur_p)->rchild = q;
    }
}


/*
 *  分裂三节点 --（这里的三节点指的是节点的三个指针域都在正常用着且有三个明确的子节点）
 * 
 *  作用： 分裂当前的原节点p， 1.处理分裂后的p的节点，2. 创建一个新节点q，并调整，然后修改ptr_data指向的值
 *        在该函数内并不对新节点q的父节点做处理
 * 
 *  三个参数：
 *  1. 第一个参数是当前节点cur-p， 并不会修改指向，只会修改其内容
 *  2. 第二个参数是插入值的指针， 会用该指针暂存当前节点cur-p与插入值之中的 中间值， 因为会把它放进父节点，需要用指针暂存，省的退出函数导致丢失
 *  3. 第三个参数是 指向 新节点 的二级指针， 它会被修改，内容也会被修改
 * 
*/
void Split(ptr_two_three cur_p, ElemType *ptr_data, two_three_node_t **q) {
    ptr_two_three temp = (*q);  // 保存q的指向的地址
    ElemType c1 = Get_Median(cur_p, *ptr_data);  // 暂存处于中间位置的值，要合并到父节点
    ElemType a1 = Get_Max(cur_p, *ptr_data);  // max val
    ElemType i1 = Get_Min(cur_p, *ptr_data);  // min val

    /* 新建节点q，并初始化、调整，主要是调整值，与两个有效子节点，一个right指针，因为是一个2节点，所以right指向null */
    (*q) = (ptr_two_three)malloc(sizeof(two_three_node_t));
    assert(*q);
    
    (*q)->data_l = a1; // 当前节点curp中的二个数据域与插入的节点data中最大的放在新节点q中
    (*q)->data_r = INT_MAX;   // 2节点右数据域 默认是intmax，作为哨兵用
    (*q)->lchild = cur_p->rchild;  // 那个被分裂的节点的右子节点赋值给新建的节点 
    (*q)->middle = temp;
    (*q)->rchild = NULL;
    // 操作当前节点的数据域，以及rchild指向null， 其他并不需要修改，
    cur_p->data_l = i1;  // 当前节点，也就是被分裂的节点的data-l数据域存放 最小的值， 因为从3节点降级成2节点，要做些修正
    cur_p->data_r = INT_MAX;
    cur_p->rchild = NULL;

    *ptr_data = c1;  // 暂存处于中间位置的值，要合并到父节点
}


/*
 * 插入方式：
 * 
 * 大致的流程框架
 * 1. 先看看是不是棵空树
 *    如果是空树，则可以直至生成一个节点 create——new——node
 * 
 * 2. 找插入的合适位置
 * 
 * 3. 查找合适的插入位置，判断节点类型, 2节点还是3节点
 *    （1） 如果是2节点，则融合
 *    （2） 如果是三节点，则分裂
 *    （3） 如果分裂的是根节点，那么，新建一个根节点     
 *    （4） 如果分裂的不是根节点，那就弹栈，继续循环
 * 
 * 
*/
void Insert23(two_three_node_t **T, ElemType data) {
    // p定义为当前操作的节点指针， q定义为新创建的节点指针， temp临时指针
    ptr_two_three p = NULL, q;

    // 定义栈结构
    unsigned int top = -1;
    ptr_two_three ancestor_table[100];

    if( (*T) == NULL ) {
        Create_New_Root(T, data, NULL);
    }
    else{
        /* 找位置  */
        p = Find_Pos(*T, data, &top, ancestor_table);
        if( p == NULL ) {
            fprintf(stderr, "插入错误，已经了，退出插入");
            exit(1);
        }
        q = NULL;
        /* 插入并调整插入过程中的各个节点，使插入后依旧还是2-3树 */
        for( ; ; ) {
            /* 判断节点类型 */
            if( p->data_r == INT_MAX ) {  // 是二节点
                Merge_In(&p, data, q);
                break;  // 是二节点直接融合就好，不会影响到父节点，退出循环就好
            }else{  /* 三节点 */
                // 1. 先分裂
                Split(p, &data, &q); // 函数执行完毕，p指向的还是原来的p，只是里面的东西变了，q也指向了其他的地址空间，并且原p地址空间也在函数内进行了一些操作
                // 2. 然后判断是否分裂的是根节点
                if( p == *T ) {
                    Create_New_Root(T, data, q);
                    break;   // 到根节点就好了，再往上也没了
                }
                else{   // 3. 如果不是分裂的根节点，则弹栈, 往上找父节点，
                    p = ancestor_table[top--];
                }
            }
        }
    }
}
