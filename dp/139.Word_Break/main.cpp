#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void helper(bool& breakable, string s, vector<string>& wordDict) {
	if(breakable == true) return;
	
	int length = wordDict.size();
	int sLen = s.size();

	for(int i = 0; i < length; i++) {
		int wordLen = wordDict[i].size();
		if(sLen < wordLen) {
			continue;
		} else {
			if(s.substr(0, wordLen) == wordDict[i]) {
				if(wordLen == sLen) {
					breakable = true;
					return;
				} else {
					helper(breakable, s.substr(wordLen, sLen), wordDict);
				}
			} else {
				continue;
			}
		}
	}
}

bool wordBreak(string s, vector<string>& wordDict) {
	bool breakable = false;
	helper(breakable, s, wordDict);
	return breakable;
}

int main(){
	string s = "aaaaaaa";
	vector<string> wordDict = {"aaaa","aaa"};
	if(wordBreak(s, wordDict)) {
		cout << "Yes" << '\n';
	}
}
