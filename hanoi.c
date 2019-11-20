#include <stdio.h>


void solve_hanoi(int num_dischi, char , char dest, char aus);

int main(int argc, char const *argv[]) {
  int num_dischi;
  printf("inserisci il numero di dischi: ");
  scanf("%d", &num_dischi);
  solve_hanoi(num_dischi, 'A', 'B', 'C');
  return 0;
}

void solve_hanoi(int num_dischi, char orig, char dest, char aus){
  if(num_dischi == 1){
    printf("sposta il disco %d da %c a %c\n", num_dischi, orig, dest);
    return;
  }
  else{
    solve_hanoi(num_dischi-1, orig, aus, dest);
    printf("sposta il disco %d da %c a %c\n", num_dischi, orig, dest);
    solve_hanoi(num_dischi-1, aus, dest, orig);
  }
  return;
}
