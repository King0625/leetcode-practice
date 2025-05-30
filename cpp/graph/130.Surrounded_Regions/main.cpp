#include <iostream>
#include <vector>

using namespace std;

const int directions[4][2] = {
	{0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

void dfs(vector<vector<char>> &board, int x, int y) {
	int rows = board.size();
	int cols = board[0].size();

	board[x][y] = '*';

	for(int d = 0; d < 4; d++) {
		int newX = x + directions[d][0];
		int newY = y + directions[d][1];

		if(newX >= 0 && newX <= rows - 1 && newY >= 0 && newY <= cols - 1 && board[newX][newY] == 'O') {
			board[newX][newY] = '*';
			dfs(board, newX, newY);
		}
	}
}

// must check four borders
void solve(vector<vector<char>>& board) {
	int rows = board.size();
	int cols = board[0].size();

	for(int i = 0; i < rows; i++) {
		if(board[i][0] == 'O') {
			dfs(board, i, 0);
		}

		if(board[i][cols-1] == 'O') {
			dfs(board, i, cols-1);
		}
	}

	for(int j = 0; j < cols; j++) {
		if(board[0][j] == 'O') {
			dfs(board, 0, j);
		}

		if(board[rows-1][j] == 'O') {
			dfs(board, rows-1, j);
		}
	}


	for(int r = 0; r < rows; r++) {
		for(int c = 0; c < cols; c++) {
			if(board[r][c] == 'O') {
				board[r][c] = 'X';
			} else if (board[r][c] == '*') {
				board[r][c] = 'O';
			}
		}
	}

}

int main(){
	vector<vector<char>> board = {
		{'X','X','X','X'},
		{'X','O','O','X'},
		{'X','X','O','X'},
		{'X','O','X','X'}
	};

	solve(board);

	for(int i = 0; i < board.size(); i++) {
		for(int j = 0; j < board[0].size(); j++) {
			cout << board[i][j] << ' ';
		}

		cout << '\n';
	}
}
