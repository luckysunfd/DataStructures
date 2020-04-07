#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#define ALPHABET_SIZE (26)

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

typedef int ElemType;

typedef struct TRIE {
    struct TRIE *items[ALPHABET_SIZE];
    bool isEndOfWord;
}trie_t, *ptr_trie;


// 生成一个新的trie节点
ptr_trie Get_New_Node(void);

// 插入
void Insert_Word(ptr_trie trie, const char *str1);

// 搜索
bool Search_Word(ptr_trie trie, const char *str1);

// show trie content
void Show_Content(ptr_trie trie, int lvl, char *word1);

void Destroy(ptr_trie trie);