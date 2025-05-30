#include <iostream>
#include <vector>

using namespace std;

string shiftingLetters(string s, vector<vector<int>>& shifts) {
	int length = shifts.size();
	int stringLen = s.size();
	vector<int> shiftDistance(stringLen, 0);
	for(int i = 0; i < length; i++) {
		for(int j = shifts[i][0]; j <= shifts[i][1]; j++) {
			int forward = 1;
			if(shifts[i][2] == 0) {
				forward = -1;
			}

			shiftDistance[j] += forward;
		}
	}

	string result = "";
	for(int i = 0; i < stringLen; i++) {
		cout << shiftDistance[i] << "|";
		shiftDistance[i] %= 25;
		cout << shiftDistance[i] << " -> ";
		if(shiftDistance[i] < 0) {
			shiftDistance[i] += 26;
		}

		char c = s[i] + shiftDistance[i];
		if(c > 'z') {
			c -= 26;
		}
		result += c;
	}

	return result;
}


int main(){
	string s = "dztz";
	vector<vector<int>> shifts = {
		{0,0,0},{1,1,1}
	};

	cout << shiftingLetters(s, shifts);
}
