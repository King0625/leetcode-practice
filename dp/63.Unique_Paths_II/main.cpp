#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int rows = obstacleGrid.size();
	int cols = obstacleGrid[0].size();

	vector<vector<int>> solutions(rows, vector<int>(cols, 0));

	if(obstacleGrid[0][0] == 0) solutions[0][0] = 1;

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			if(i > 0 && j > 0 && obstacleGrid[i][j] == 0) {
				solutions[i][j] = solutions[i - 1][j] + solutions[i][j - 1];
			}else if(i > 0 && obstacleGrid[i][j] == 0) {
				solutions[i][j] = solutions[i - 1][j];	
			}else if(j > 0 && obstacleGrid[i][j] == 0) {
				solutions[i][j] = solutions[i][j - 1];
			}
		}
	}

	return solutions[rows-1][cols-1];
}

int main(){
	vector<vector<int>> obstacleGrid = {
		{0,0,0},
		{0,1,0},
		{0,0,0}
	};

	cout << uniquePathsWithObstacles(obstacleGrid) << '\n';
}
