#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	string result = strs[0];
	
	int length = strs.size();

	for(int i = 1; i < length; i++) {
		int currentStrLen = strs[i].size();
		int lastPrefixLen = result.size();

		if(lastPrefixLen == 0) break;

		string temp = "";

		int j = 0;
		bool end = false;
		while(j < min(currentStrLen, lastPrefixLen) && !end) {
			if(result[j] == strs[i][j]) {
				temp += result[j];
			} else {
				end = true;
			}

			j++;
		}
	
		result = temp;
	}
	
	return result;
}

int main(){
	vector<string> strs = {"dog","racecar","car"};
	cout << longestCommonPrefix(strs);
}
