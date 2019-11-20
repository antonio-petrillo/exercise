#include <stdio.h>
#include <stdlib.h>

int** make_board(int dim);
void print_board(int** board, int dim);
int solve_puzzle(int** board,  int dim, int Column);
int secure_position(int** board, int dim, int Raw, int Column);

int main(int argc, char* argv[]){
	int	 n;
	int** board;
	if(argc == 1){
		printf("inserisci la dimensione della scacchiera: ");
		scanf("%d", &n);
	}
	else if(argc == 2){
		n = atoi(argv[1]);
	}
	else{
		printf("errore nella sintassi\nSyntax: queen_generalizzato dim_matrice\n");
		exit(0);
	}
	board = make_board(n);
	if(solve_puzzle(board, n, 0)){
		printf("problema risolto\n");
		print_board(board, n);
	}
	else{
		printf("impossibile risolvere il problema\n");
	}
	return 0;
}

int** make_board(int dim){
	int** board = (int**) calloc(dim, sizeof(int*));
	if(!board) {printf("errore nella creazione della scacchiera\n"); exit(0);}
	for(int i=0; i<dim; i++){
		board[i] = (int*) calloc(dim, sizeof(int));
		if(!board[i]) {printf("errore nella creazione della scacchiera\n"); exit(0);}
	}
	return board;
}

void print_board(int** board, int dim){
	puts("");
	for(int i=0; i<dim; i++){
		for(int j=0; j<dim; j++)
			printf("%3d", board[i][j]);
		puts("");
	}
	puts("");
}

int solve_puzzle(int** board,  int dim, int Column){
	if(Column >= dim) return 1;
	else{
		for(int i=0; i<dim; i++){
			if(secure_position(board, dim, i, Column)){
				board[i][Column] = 1;
				if(solve_puzzle(board, dim, Column+1)) return 1;
				board[i][Column] = 0;
			}
		}
		return 0;
	}
}

int secure_position(int** board, int dim, int Raw, int Column){
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
		if(board[z][t])return 0;
		z++; t--;
	}
	return 1;
}
