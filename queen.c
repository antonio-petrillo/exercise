#include <stdio.h>

void print_board(int board[][8]);
int solve_puzzle(int board[][8], int Column);
int posizione_sicura(int board[][8], int Raw, int Column);

int main(){
	int board[8][8] = {0};
	if(solve_puzzle(board, 0)){
		printf("problema risolto\nZACC NDA TENAGLIA\n");
		print_board(board);
	}
	else{
		printf("non riesco a risolvere il problema c'è qualche problema\n");
	}
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
	return;
}

int solve_puzzle(int board[][8], int Column){
	if(Column >= 8){
		return 1;
	}
	for(int i=0; i<8; i++){
		if(posizione_sicura(board, i, Column)){
			board[i][Column] = 1;
			//print_board(board);
			//getchar();
			if(solve_puzzle(board, Column+1)){
				return 1;
			}
			board[i][Column] = 0;
		}
	}
	return 0;	
}
int posizione_sicura(int board[][8], int Raw, int Column){
	int flag = 0;
	int i=Raw, j=Column;
	for(int z=0; z<Raw; z++){
		if(board[z][Column]) return 0;
	}
	for(int z=0; z<Column; z++){
		if(board[Raw][z]) return 0;
	}
	int z=Raw-1, t=Column-1;
	while(z>=0 && t>=0){
		if(board[z][t]) return 0;
		z--; t--;
	}
	z=Raw+1, t=Column-1;
	while(z<=7 && t>=0){
		if(board[z][t]) return 0;
		z++; t--;
	}
	return 1;
}
