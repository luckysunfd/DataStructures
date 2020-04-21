#include "hash_table.h"

const int HT_PRIME_1 = 151;
const int HT_PRIME_2 = 163;

const ptr_hash_item HT_DELETED_ITEM = {NULL}; 


ptr_hash_item Init_Hash_Item(const char *key, const char *value) {
    ptr_hash_item new_item = (ptr_hash_item)malloc(sizeof(hash_item));
    assert(new_item);
    new_item->key = strdup(key);
    new_item->value = strdup(value);

    return new_item;
}
 
/*
ptr_hash_item Init_Hash_Item(const char *key, const char *value) {
    ptr_hash_item new_item = (ptr_hash_item)malloc(sizeof(hash_item));
    assert(new_item);
    new_item->key = strdup(key);
    new_item->value = strdup(value);

   return new_item; 
}
*/

void Init_Hash_Table(hash_table **ht) {
    (*ht) = (ptr_hash_table)malloc(sizeof(hash_table)) ;
    assert(*ht);
    (*ht)->cur_size = 0;
    memset( (*ht)->container, 0, sizeof(ptr_hash_item) * DEFAULT_ARR_SIZE );
    (*ht)->capacity = DEFAULT_ARR_SIZE;   
}


void Release_Hash_Item(ptr_hash_item item) {
    if(item == NULL)
        return ;
    
    free(item->key);
    free(item->value);
    free(item);
}

// 只是简单的顺着数组偏移从0-cur_size，开始释放每个哈希项占用的内存空间
void Release_Hash_Table(ptr_hash_table ht) {
    if(ht == NULL) 
        return ;
    
    for(int i = 0; i < ht->cur_size; i++) {
        ptr_hash_item temp = ht->container[i];
        if(temp != NULL) {
            Release_Hash_Item(temp);
        }
    }

    free(ht);
}


unsigned int Cal_HashV(const char *s, const int a, const int m) {
    long hash = 0;
    const int len_s = strlen(s);

    for(int i = 0; i < len_s; i++) {
        hash = hash + (long)pow(a, len_s - (i+1)) * s[i];
        hash = hash % m;
    }

    return (int)hash;
}


unsigned int ReHash(const char *s, const int num_buckets, const int attempt) {
    const int hash_a = Cal_HashV(s, HT_PRIME_1, num_buckets);
    const int hash_b = Cal_HashV(s, HT_PRIME_2 , num_buckets);

    return (hash_a + (attempt * (hash_b +1 ))) % num_buckets ;
}


void Insert_HT(ptr_hash_table ht, const char *key, const char *value) {
    ptr_hash_item ni = Init_Hash_Item(key, value);

    unsigned int index = Cal_HashV(ni->key, HT_PRIME_1, ht->capacity);
    
    ptr_hash_item cur_item = ht->container[index];

    int i = 1; 
    /*
    while( cur_item != NULL && cur_item != &HT_DELETED_ITEM ) {
        index = ReHash(ni->key, ht->capacity, i);
        cur_item = ht->container[index];
        i++;
    }
    */
    while( cur_item != NULL ) {
        // index = ReHash(ni->key, ht->capacity, i);
        // cur_item = ht->container[index];

        if( cur_item != &HT_DELETED_ITEM ) {
            if( strcmp(cur_item->key, key) == 0 ) {
                Release_Hash_Item(cur_item);
                ht->container[index] = ni;
                return ;
            }
        }
        index = ReHash(ni->key, ht->capacity, i);
        cur_item = ht->container[index];
        i++;
    }

    ht->container[index] = ni;
    ht->cur_size++;
}


char* Search_HT(ptr_hash_table ht, const char *key) {
    int index = Cal_HashV(key, HT_PRIME_1, ht->capacity);
    ptr_hash_item cur_item = ht->container[index];

    int i = 1;

    while( cur_item != NULL ) {
        if(cur_item != &HT_DELETED_ITEM) {
            if( strcmp(cur_item->key, key) == 0 ) {
                return cur_item->value;
            }
        }

        index = ReHash(key, ht->capacity, i);
        cur_item = ht->container[index];
        i++;
    }
    
    return NULL;
}


void Del_Item_HT(ptr_hash_table ht, const char *key) {
   int index = Cal_HashV(key, ht->capacity, 0);
   ptr_hash_item cur_item = ht->container[index];
   int i = 1;

   while( cur_item != NULL ) {
       if( cur_item != &HT_DELETED_ITEM ) {
           if( strcmp(cur_item->key, key) == 0 ) {
               Release_Hash_Item(cur_item);
               ht->container[index] = &HT_DELETED_ITEM;
           }
       }
       index = ReHash(key, ht->capacity, i);
       cur_item = ht->container[index];
       i++;
   }

   ht->cur_size--;
}
