#include <iostream>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
	if(numRows == 1) return s;
	vector<string> converted(numRows, "");

	int position = 0;
	bool reversed = false;

	for (int i = 0; i < s.size(); i++) {
		converted[position] += s[i];
		if (!reversed) {
			if (position < numRows - 1) {
				position++;
			} else {
				position--;
				reversed = true;
			}
		} else if (reversed) {
			if (position >= 1) {
				position--;
			} else {
				position++;
				reversed = false;
			}
		}
	}

	string result = "";
	for (int j = 0; j < converted.size(); j++) {
		result += converted[j];
	}

	return result;
}

int main(){
	string s = "PAYPALISHIRING";
	int numRows = 2;
	cout << convert(s, numRows) << '\n';
}
