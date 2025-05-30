#include <iostream>
#include <vector>
using namespace std;

bool find(vector<vector<char>>& board, int row, int col) {
	return false;
}


vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	
}

int main(){
	vector<vector<char>> board = {
		{'o','a','a','n'},
		{'e','t','a','e'},
		{'i','h','k','r'},
		{'i','f','l','v'}
	};

	vector<string> words = {"oath","pea","eat","rain"};
	vector<string> result = findWords(board, words);

	for(string s: result) {
		cout << s << " ";
	}
}
