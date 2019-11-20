#include <stdio.h>
#include <time.h>

int horizontal[] = {2, 2, 1, 1, -1, -1, -2, -2};
int vertical[] = {1, -1, 2, -2, 2, -2, 1, -1};

void print_board(int board[][8]);
int move(int board[][8], int Row, int Column, int count);

int main(int argc, char const *argv[]) {
  int Row , Column , count = 1;
  printf("inserci la posizione iniziale del cavallo (compreso tra 1 e 8): ");
  scanf("%d%d", &Row, &Column);
  Row--; Column--;
  int board[8][8] = {0};
  clock_t start = clock();
  if(move(board, Row, Column, count)){
    printf("giro completato\a\n");
    print_board(board);
  }
  else{
    printf("impossibile completare il giro da questa posizione iniziale\n");
  }
  clock_t end = clock();
  printf("tempo di esecuzione: %lf\n", (double)(end-start)/CLOCKS_PER_SEC);
  return 0;
}

void print_board(int board[][8]){
  puts("");
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++)
      printf("%3d", board[i][j]);
    puts("");
  }
  puts("");
}
int move(int board[][8], int Row, int Column, int count){
    if(((Row<0 || Row>7) || (Column<0 || Column>7)) || board[Row][Column]){
      return 0;
    }
    else{
      board[Row][Column] = count;
      if(count == 64) return 1;
      //print_board(board);
      //getchar();
      for(int i=0; i<8; i++){
        int newRow = Row+vertical[i];
        int newColumn = Column+horizontal[i];
        int result = move(board, newRow, newColumn, count+1);
        if(result){
          return 1;
        }
      }
      board[Row][Column] = 0;
      return 0;
    }
}
