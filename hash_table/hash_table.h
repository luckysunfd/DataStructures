#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <assert.h>


#define DEFAULT_ARR_SIZE 50

// const int HT_PRIME_1 = 151;
// const int HT_PRIME_2 = 163;

// const ptr_hash_item HT_DELETED_ITEM = {NULL, NULL}; 

// 哈希表键值对结构 
typedef struct HASH_ITEM {
    char *key;
    char *value;
}hash_item, *ptr_hash_item;

// 哈希表结构
typedef struct HASH_TABLE {
    ptr_hash_item container[DEFAULT_ARR_SIZE];
    unsigned int cur_size;
    unsigned int capacity;
}hash_table, *ptr_hash_table; 

// const ptr_hash_item HT_DELETED_ITEM = {NULL}; 

/*
 *  初始化 键值对
 *  
 *  传递进来两个字符串，赋给kv 成员
 *
 *  并返回初始化之后的指针
*/
ptr_hash_item Init_Hash_Item(const char *key, const char *value);


/*
 * 初始化哈希表 
 * 
*/
void Init_Hash_Table(hash_table **ht);


/*
 * 释放哈希表项、哈希表的内存空间
 *
*/
void Release_Hash_Item(ptr_hash_item item);
void Release_Hash_Table(ptr_hash_table ht);

/*
 * 计算哈希值
 *
*/
unsigned int Cal_HashV(const char *s, const int a, const int m);

/*
 * 冲突处理策略
 *
 * 开放地址再哈希方法
 *
*/
unsigned int ReHash(const char *s, const int num_buckets, const int attempt);


/*
 * 1. 插入到哈希表
 * 2. 搜索某个字符串在某个哈希表中
 * 3. 删除某个字符串，如果存在的话
 * 
*/
void Insert_HT(ptr_hash_table ht, const char *key, const char *value);

char* Search_HT(ptr_hash_table ht, const char *key);

void Del_Item_HT(ptr_hash_table ht, const char *key);


