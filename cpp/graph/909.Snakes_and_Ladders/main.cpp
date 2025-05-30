#include <iostream>
#include <vector>

using namespace std;

int directions[4][2] = {
	{0,1}, {1,0}, {0, -1}, {-1, 0}
};

int snakesAndLadders(vector<vector<int>>& board) {
	int width = board.size();

}

int main(){
	vector<vector<int>> board = {
		{-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1},
		{-1,35,-1,-1,13,-1},
		{-1,-1,-1,-1,-1,-1},
		{-1,15,-1,-1,-1,-1}
	};

	cout << snakesAndLadders(board) << '\n';
}
