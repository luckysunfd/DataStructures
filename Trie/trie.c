#include "trie.h"




// 生成一个新的trie节点
ptr_trie Get_New_Node(void) {
    ptr_trie new_node = (ptr_trie)malloc(sizeof(trie_t));
    assert(new_node);

    memset(new_node->items, 0, sizeof(ElemType) * ALPHABET_SIZE);
    new_node->isEndOfWord = false;

    return new_node;
}

// 插入
void Insert_Word(ptr_trie trie, const char *str1) {
    if( trie == NULL)
        return ;

    ptr_trie cur = trie;
    int tn_i;

    for(int i =0; i < strlen(str1); i++) {
        tn_i = CHAR_TO_INDEX(str1[i]); // 从字符串str1中按顺序读取每个字符，并转换成0-25的数组偏移
        if( cur->items[tn_i] == NULL ) {
            cur->items[tn_i] = Get_New_Node(); // 生成一个新trie节点
        }
        cur = cur->items[tn_i];  // 更新游标指针指向
    }
    cur->isEndOfWord = true; // 读完了str1，然后在最后一个节点设置终止标志为true，表示从这里往上构成一个完整的单词
}

// 搜索
bool Search_Word(ptr_trie trie, const char *str1) {
    if( trie == NULL ) {
        return false;
    }
    
    int tn_i;
    ptr_trie cur = trie;
    for( int i = 0; i < strlen(str1); i++) {
        tn_i = CHAR_TO_INDEX(str1[i]);
        if( cur->items[tn_i] == NULL )
            return false;
        cur = cur->items[tn_i];
    }

    return cur != NULL && cur->isEndOfWord;
}

// show trie content
void Show_Content(ptr_trie trie);

void Destroy(ptr_trie trie) {
    if( trie != NULL ) {
        free(trie);
    }
}