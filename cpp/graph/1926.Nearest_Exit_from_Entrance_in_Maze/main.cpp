#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int directions[4][2] = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};

int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
	int row = maze.size();
	int col = maze[0].size();

	int x = entrance[0];
	int y = entrance[1];

	vector<vector<int>> distance(row, vector<int>(col, INT_MAX));
	distance[x][y] = 0;

	int minDistance = INT_MAX;

	queue<pair<int,int>> q;

	q.push({x,y});


	while(!q.empty()) {
		auto [currentX, currentY] = q.front();
		maze[currentX][currentY] = '*';

		if(!(currentX == x && currentY == y) && (currentX == 0 || currentY == 0 || currentX == row - 1 || currentY == col - 1)) {
			minDistance = min(minDistance, distance[currentX][currentY]);
		}

		q.pop();

		for(int d = 0; d < 4; d++) {
			int newX = currentX + directions[d][0];
			int newY = currentY + directions[d][1];

			if(newX >= 0 && newX < row && newY >= 0 && newY < col && maze[newX][newY] == '.') {
				if(distance[currentX][currentY] + 1 < distance[newX][newY]) {
					distance[newX][newY] = distance[currentX][currentY] + 1;
					q.push({newX, newY});
				}
			}
		}
	}

	if(minDistance == INT_MAX) return -1;
	return minDistance;
}

int main(){
	vector<vector<char>> maze = {
		{'+','+','+'},
		{'.','.','.'},
		{'+','+','+'}
	};

	vector<int> entrance = {1,0};
	cout << nearestExit(maze, entrance);
}
