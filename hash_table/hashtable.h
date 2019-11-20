#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE 3

typedef struct node{
  struct node* next;
  char* key;
  char* value;
}Node;

typedef Node* NodePtr;
typedef Node* List;
typedef NodePtr* SubList;

typedef struct{
  SubList entries;
}ht_t;

typedef ht_t* hashtable;

void error_managing(char* str);
unsigned int hash(const char* key);
hashtable create_hashtable();
NodePtr ht_pair(const char* key, const char* value);
void set_hashtable(hashtable* ht, const char* key, const char* value);
char* get_hashtable(hashtable ht, const char* key);
void print_ht(hashtable ht);
hashtable delete_ht(hashtable ht);

#endif
