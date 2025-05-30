#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool helper(int start, string s, unordered_set<string>& wordSet, vector<int>& dp) {
	int sLen = s.size();
	if(start == sLen) return true;
	if(dp[start] != -1) return dp[start];

	for(int i = start; i < sLen; i++) {
		string part = s.substr(start, i - start + 1);
		if(wordSet.count(part) && helper(i+1, s, wordSet, dp)) {
			dp[start] = true;
			return dp[start];
		}
	}

	dp[start] = false;
	return dp[start];
}

bool wordBreak(string s, vector<string>& wordDict) {
	unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
	int sLen = s.size();
	vector<int> dp(sLen, -1);
	return helper(0, s, wordSet, dp);
}

int main(){
	string s = "aaaaaaa";
	vector<string> wordDict = {"aaaa","aaa"};
	if(wordBreak(s, wordDict)) {
		cout << "Yes" << '\n';
	}
}
