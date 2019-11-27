#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hashtable.h"

int main(int argc, char const *argv[]) {
  hashtable ht = create_hashtable();
  set_hashtable(&ht, "chiave1", "Luca");
  set_hashtable(&ht, "chiave2", "Giurato");
  set_hashtable(&ht, "chiave3", "Sconosciuto");
  set_hashtable(&ht, "chiave4", "Buongiollo");
  set_hashtable(&ht, "chiave5", "Puja");
  printf("ricerca del valore %s: %s\n", "chiave1", get_hashtable(ht, "chiave1"));
  printf("ricerca del valore %s: %s\n", "chiave2", get_hashtable(ht, "chiave2"));
  printf("ricerca del valore %s: %s\n", "chiave3", get_hashtable(ht, "chiave3"));
  printf("ricerca del valore %s: %s\n", "chiave4", get_hashtable(ht, "chiave4"));
  printf("ricerca del valore %s: %s\n", "chiave5", get_hashtable(ht, "chiave5"));
  printf("ricerca del valore %s: %s\n", "chiave6", get_hashtable(ht, "chiave6"));
  puts("\n");
  print_ht(ht);
  puts("\nprovo a sovrascrivere un valore");
  set_hashtable(&ht, "chiave1", "Marco");
  set_hashtable(&ht, "chiave2", "Betello");
  set_hashtable(&ht, "chiave3", "uno piacere ha il grande piacere");
  set_hashtable(&ht, "chiave4", "e con questa non tizia'");
  set_hashtable(&ht, "chiave5", "Qualcosa di serio");
  set_hashtable(&ht, "chiave7", "Isaac");
  set_hashtable(&ht, "chiave97", "Asimov");
  print_ht(ht);
  puts("\n");
  ht = delete_ht(ht);
  puts("\n");
  print_ht(ht);
  return 0;
}
