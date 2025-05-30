#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
}

int main(){
	vector<vector<char>> matrix = {
		{'1','0','1','0','0'},
		{'1','0','1','1','1'},
		{'1','1','1','1','1'},
		{'1','0','0','1','0'}
	};

	cout << maximalSquare(matrix) << '\n';
}
