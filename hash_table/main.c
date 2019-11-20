#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hashtable.h"

int main(int argc, char const *argv[]) {
  hashtable ht = create_hashtable();
  set_hashtable(&ht, "chiave1", "Antonio");
  set_hashtable(&ht, "chiave2", "Giuseppe");
  set_hashtable(&ht, "chiave3", "Sconosciuto");
  set_hashtable(&ht, "chiave4", "Puja");
  set_hashtable(&ht, "chiave5", "Chita");
  printf("ricerca del valore %s: %s\n", "chiave1", get_hashtable(ht, "chiave1"));
  printf("ricerca del valore %s: %s\n", "chiave2", get_hashtable(ht, "chiave2"));
  printf("ricerca del valore %s: %s\n", "chiave3", get_hashtable(ht, "chiave3"));
  printf("ricerca del valore %s: %s\n", "chiave4", get_hashtable(ht, "chiave4"));
  printf("ricerca del valore %s: %s\n", "chiave5", get_hashtable(ht, "chiave5"));
  printf("ricerca del valore %s: %s\n", "chiave6", get_hashtable(ht, "chiave6"));
  puts("\n");
  print_ht(ht);
  puts("\nprovo a sovrascrivere un valore");
  set_hashtable(&ht, "chiave1", "Gigio");
  set_hashtable(&ht, "chiave2", "Batu");
  set_hashtable(&ht, "chiave3", "mamma");
  set_hashtable(&ht, "chiave4", "papa'");
  set_hashtable(&ht, "chiave5", "dodo");
  set_hashtable(&ht, "chiave7", "io");
  set_hashtable(&ht, "chiave97", "sempre io");
  print_ht(ht);
  puts("\n");
  ht = delete_ht(ht);
  puts("\n");
  print_ht(ht);
  return 0;
}
