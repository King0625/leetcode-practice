#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int directions[4][2] = {
	{0,1},{1,0},{0,-1},{-1,0}
};

void dfs(vector<vector<int>>& grid, int x, int y, int& area) {
	area++;
	grid[x][y] = 0;
	int len = grid.size();

	for(int i = 0; i < 4; i++) {
		int newX = x + directions[i][0];
		int newY = y + directions[i][1];
		if(newX >= 0 && newX < len && newY >= 0 && newY < len && grid[newX][newY] == 1) {
			dfs(grid, newX, newY, area);
		} 
	}
}

int countIsland(vector<vector<int>>& grid) {
	vector<vector<int>> gridCopy = grid;
	int len = gridCopy.size();
	int maxArea = -1;
	for(int i = 0; i < len; i++) {
		for(int j = 0; j < len; j++) {
			if(gridCopy[i][j] == 1) {
				int area = 0;
				dfs(gridCopy,i,j,area);
				maxArea = max(maxArea, area);
			}
		}
	}

	return maxArea;
}

int largestIsland(vector<vector<int>>& grid) {
	int len = grid.size();
	vector<pair<int,int>> zeroAreas;

	for(int i = 0; i < len; i++) {
		for(int j = 0; j < len; j++) {
			if(grid[i][j] == 0) {
				zeroAreas.push_back(make_pair(i,j));
			}
		}
	}

	int maxArea = countIsland(grid);

	for(pair<int,int> zeroArea: zeroAreas) {
		int row = zeroArea.first;
		int col = zeroArea.second;
		grid[row][col] = 1;
		int currentArea = countIsland(grid);
		maxArea = max(maxArea, currentArea);

		grid[row][col] = 0;
	}

	return maxArea;

}


int main(){
	vector<vector<int>> grid = {
		{1,1,0},
		{0,0,1},
		{1,0,1}
	};

	cout <<	largestIsland(grid) << '\n';
	return 0;
}
