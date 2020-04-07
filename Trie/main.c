#include "trie.h"



int main(void) {
    // 字典文件，一行一个独立单词，大概有2w个
    const char *dict_file_path = "/Users/sun/Documents/20.txt";
    FILE *fp = fopen(dict_file_path, "r");

    if( fp == NULL){
        perror("打开文件失败, 退出了退出了 Error:");
        exit(1);
    }

    char templine[50];
    ptr_trie trie1 = Get_New_Node();
    int cnt = 0;

    puts("从外部文件按行读取单词，放入字典树中，直到到达文件末尾");

    while( fscanf(fp, "%[^\n]%*c", templine )  != EOF ) {
        printf("插入%s\n", templine);
        Insert_Word(trie1, templine);
        cnt++;
    }

    printf("总共插入%d\n",cnt);

    if( Search_Word(trie1, "dade") ) {
        puts("dade in the trie");
    }

    if( Search_Word(trie1, "funny1") ) {
        puts("funny1 in the trie");
    }

    int lvl = 0;
    char word1[60];
    
    Show_Content(trie1, lvl, word1);
    
    fclose(fp);
    Destroy(trie1);
    puts("--------");

    return 0;
}