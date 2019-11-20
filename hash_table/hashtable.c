#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hashtable.h"

void error_managing(char* str){
    if(!strcmp(str, ""))
      printf("Errore: %s\n", str);
    else
      printf("Errore nell'esecuzione del programma\n");
    exit(0);
}

unsigned int hash(const char* key){
  unsigned long int value = 0;
  unsigned int key_len = strlen(key);
  for(unsigned int i = 0; i < key_len ; i++)
    value = value*41 + key[i];
  value %= TABLE_SIZE;
  return value;
}

hashtable create_hashtable(){
    hashtable ht = (hashtable) malloc(sizeof(ht_t));
    if(!ht) error_managing("impossibile creare hashtable");
    ht->entries = (SubList) calloc(TABLE_SIZE, sizeof(List));
    if(!ht->entries) error_managing("impossibile creare le entries dell'hashtable");
    return ht;
}

NodePtr ht_pair(const char* key, const char* value){
    NodePtr newnode = (NodePtr)malloc(sizeof(Node));
    if(!newnode) error_managing("impossibile creare il nuovo nodo");
    newnode->next = NULL;
    newnode->key = (char*) calloc(strlen(key)+1, sizeof(char));
    if(!newnode->key) error_managing("impossibile allocare memoria per la chiave");
    newnode->value = (char*) calloc(strlen(value)+1, sizeof(char));
    if(!newnode->value) error_managing("impossibile allocare memoria per il valore");
    strcpy(newnode->key, key);
    strcpy(newnode->value, value);
    return newnode;
}

void set_hashtable(hashtable* ht, const char* key, const char* value){
  unsigned int slot = hash(key);
  NodePtr entry = (*ht)->entries[slot];
  if(!entry){
    NodePtr newnode = ht_pair(key, value);
    (*ht)->entries[slot] = newnode;
    return;
  }
  NodePtr prev = NULL;
  while(entry){
    if(!strcmp(entry->key, key)) break;
    prev = entry;
    entry = entry->next;
  }
  if(!prev){
    NodePtr newnode = ht_pair(key, value);
    newnode->next = entry->next;
    (*ht)->entries[slot] = newnode;
    free(entry);
  }
  else if(!entry){
    NodePtr newnode = ht_pair(key, value);
    prev->next = newnode;
  }
  else{
    NodePtr newnode = ht_pair(key, value);
    prev->next = newnode;
    newnode->next = entry->next;
    free(entry);
  }
  return;
}

char* get_hashtable(hashtable ht, const char* key){
  unsigned int slot = hash(key);
  List entry= ht->entries[slot];
  if(!entry) return NULL;
  while(entry){
    if(!strcmp(key, entry->key))
      return entry->value;
    entry = entry->next;
  }
  return NULL;
}

void print_ht(hashtable ht){
  if(!ht) {printf("hashtable vuota\n"); return;}
  for(unsigned int i = 0; i < TABLE_SIZE; i++){
    List entry = ht->entries[i];
    if(!entry) continue;
    printf("%3d: ", i);
    while(entry){
      printf("%s=%s\t", entry->key, entry->value);
      entry = entry->next;
    }
    puts("");
  }
}

hashtable delete_ht(hashtable ht){
  if(!ht) return NULL;
  for(unsigned int i = 0; i < TABLE_SIZE; i++){
    if(!ht->entries[i]) continue;
    while(ht->entries[i]){
      NodePtr tmp = ht->entries[i];
      ht->entries[i] = ht->entries[i]->next;
      printf("Elimino: %s=%s\n", tmp->key, tmp->value);
      free(tmp);
    }
    free(ht->entries[i]);
  }
  free(ht);
  return NULL;
}
