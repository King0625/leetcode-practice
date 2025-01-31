#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int dfs(vector<vector<int>>& grid, int x, int y, int islandId) {
	int len = grid.size();
	if(x < 0 || x >= len || y < 0 || y >= len || grid[x][y] != 1) {
		return 0;
	}
	grid[x][y] = islandId;

	return 1 +
		dfs(grid, x + 1, y, islandId) +
		dfs(grid, x - 1, y, islandId) +
		dfs(grid, x, y + 1, islandId) +
		dfs(grid, x, y - 1, islandId);
}

int largestIsland(vector<vector<int>>& grid) {
	unordered_map<int,int> islandSizes;
	int len = grid.size();
	int islandId = 2;

	for(int i = 0; i < len; i++) {
		for(int j = 0; j < len; j++) {
			if(grid[i][j] == 1) {
				islandSizes[islandId] = dfs(grid, i, j, islandId);
				islandId++;
			}
		}
	}

	if(islandSizes.empty()) return 1;

	if(islandSizes.size() == 1) {
		islandId--;
		return islandSizes[islandId] == len * len
			? islandSizes[islandId] : islandSizes[islandId] + 1;
	}

	int maxArea = 1;
	
	for(int i = 0; i < len; i++) {
		for(int j = 0; j < len; j++) {
			if(grid[i][j] == 0) {
				int currentArea = 1;
				unordered_set<int> neighboringIslands;
				if(i - 1 >= 0 && grid[i-1][j] > 1) {
					neighboringIslands.insert(grid[i-1][j]);
				}

				if(i + 1 < len && grid[i+1][j] > 1) {
					neighboringIslands.insert(grid[i+1][j]);
				}

				if(j - 1 >= 0 && grid[i][j-1] > 1) {
					neighboringIslands.insert(grid[i][j-1]);
				}

				if(j + 1 < len && grid[i][j+1] > 1) {
					neighboringIslands.insert(grid[i][j+1]);
				}

				for(int id: neighboringIslands) {
					currentArea += islandSizes[id];
				}

				maxArea = max(maxArea, currentArea);
			}
		}
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
