#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int directions[4][2] = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};

void dfs(vector<vector<char>> &grid, int x, int y) {
	int row = grid.size();
	int col = grid[0].size();

	grid[x][y] = 0;
	for(int d = 0; d < 4; d++) {
		int newX = x + directions[d][0];
		int newY = y + directions[d][1];
		if(newX >= 0 && newX < row && newY >=0 && newY < col && grid[newX][newY] == '1') {
			dfs(grid, newX, newY);
		}
	}
}

int numIslands(vector<vector<char>>& grid) {
	int row = grid.size();
	int col = grid[0].size();
	int count = 0;

	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++){
			if(grid[i][j] == '1') {
				count++;
				dfs(grid, i, j);
			}
		}
	}

	return count;
}

int main(){
	vector<vector<char>> grid = {
		{'1', '1', '1', '0', '0'},
		{'1', '1', '1', '1', '0'},
		{'0', '0', '1', '0', '0'},
		{'0', '0', '0', '0', '0'}
	};
	//	vector<vector<char>> grid = {
	//		{'0'},
	//	};
	cout <<  numIslands(grid) << '\n';

}
