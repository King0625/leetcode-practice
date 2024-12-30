#include <iostream>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
	if(numRows == 1) return s;
	vector<vector<char>> converted(numRows);
	
	//4 + (4 - 2) + 4 + (4 - 2)
	int position = 0;
	bool reversed = false;

	for(int i = 0; i < s.size(); i++) {
		converted[position].push_back(s[i]);
		if(!reversed) {
			if(position < numRows - 1){
				position++;
			} else {
				position--;
				reversed = true;
			}
		} else if (reversed) {
			if(position >= 1) {
				position--;
			} else {
				position++;
				reversed = false;
			}
		}
	}

	string result = "";
	for(int j = 0; j < converted.size(); j++) {
		for(char c: converted[j]) {
			result += c;
		}
	}

	return result;
}

int main(){
	string s = "PAYPALISHIRING";
	int numRows = 2;
	cout << convert(s, numRows) << '\n';
}
