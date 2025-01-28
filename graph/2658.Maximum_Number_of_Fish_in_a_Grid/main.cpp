#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int directions[4][2] = {
	{0,1},{1,0},{0,-1},{-1,0}
};

void dfs(vector<vector<int>>& grid, int x, int y, int& count) {
	int row = grid.size();
	int col = grid[0].size();
	count += grid[x][y];
	grid[x][y] = 0;

	for(int i = 0; i < 4; i++) {
		int newX = x + directions[i][0];
		int newY = y + directions[i][1];
		if(newX >= 0 && newX < row && newY >= 0 && newY < col && grid[newX][newY] != 0) {
			dfs(grid, newX, newY, count);
		}
	}
}

int findMaxFish(vector<vector<int>>& grid) {
	int result = 0;
	int row = grid.size();
	int col = grid[0].size();

	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			if(grid[i][j] != 0) {
				int count = 0;
				dfs(grid, i, j, count);
				result = max(result, count);
			}
		}
	}
	return result;
}

int main(){
	vector<vector<int>> grid = {
		{0,2,1,0},
		{4,0,0,3},
		{1,0,0,4},
		{0,3,2,0}
	};

	cout << findMaxFish(grid) << '\n';
	return 0;
}
