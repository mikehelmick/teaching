#include <iostream>
using namespace std;

enum player {
	PLAYER1,
	PLAYER2,
	NONE
};

// This is clunky - and not extensible. You don't want to do this.
void init_board(player board[3][3], int x_dim, int y_dim, player init_value) {
	for (int i = 0; i < x_dim; i++) {
		for (int j = 0; j < y_dim; j++) {
			board[i][j] = init_value;
		}
	}
}

int main() {
	const int B_SIZE = 3;
	player board[B_SIZE][B_SIZE];
	init_board(board, B_SIZE, B_SIZE, NONE);

  print_board(board, B_SIZE, B_SIZE)
}