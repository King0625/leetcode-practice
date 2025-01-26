#include <iostream>
#include <vector>

using namespace std;

class Solution {
	private:
		string mx, my, md1, md2;
		vector<vector<string>> solutions;

		void backtrack(int n, vector<string>& solution, int x, int y, int c) {
			int diagonols = n*2-1;
			if(y == n) {
				x++;
				y = 0;
			}

			if(x == n) {
				if(c != n) return;
				solutions.push_back(solution);
				return;
			}

			int d1 = (x+y) % diagonols;
			int d2 = (x-y+diagonols) % diagonols;

			if(mx[x] == '.' && my[y] == '.' && md1[d1] == '.' && md2[d2] == '.') {
				mx[x] = my[y] = md1[d1] = md2[d2] = 'Q';
				solution[x][y] = 'Q';
				backtrack(n, solution, x, y+1, c+1);
				mx[x] = my[y] = md1[d1] = md2[d2] = '.';
			}

			solution[x][y] = '.';
			backtrack(n, solution, x, y+1, c);
		}

	public:
		vector<vector<string>> solveNQueens(int n) {
			vector<string> solution(n, string(n, '.'));
			mx = string(n, '.');
			my = string(n, '.');
			md1 = string(n*2-1, '.');
			md2 = string(n*2-1, '.');
			backtrack(n, solution, 0, 0, 0);
			return solutions;
		}	
};


int main(){
	int n = 4;
	Solution *s = new Solution();
	vector<vector<string>> result = s->solveNQueens(n);
	int length = result.size();

	for(int i = 0; i < length; i++) {
		for(string s: result[i]) {
			cout << s << '\n';
		}

		cout << "\n\n";
	}

	return 0;
}
