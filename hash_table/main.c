#include "hash_table.h"



int main(void) {

    ptr_hash_table ht = NULL;

    Init_Hash_Table(&ht);

    char *keys[] = {
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
    }; 
    char *value[] = {
        "111",
        "222",
        "333",
        "444",
        "555",
        "666",
        "777",
        "888"
    };

    for(int i = 0; i < 8; i++) {
        Insert_HT(ht, keys[i], value[i]);
    }

    if( Search_HT(ht, "four") ) {
        puts("In!");
    }

    if( !Search_HT(ht, "ten") ) {
        puts("Not In");
    }

    return 0;
}
