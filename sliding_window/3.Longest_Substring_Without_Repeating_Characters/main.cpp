#include <iostream>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
	int len = s.size();

	if(len <= 1) return len;

	unordered_set<char> charSet;
	charSet.insert(s[0]);	
	
	int maxLen = 1;

	int left = 0;
	int right = 1;

	while(left <= right && right < len) {
		if(charSet.count(s[right])) {
			charSet.erase(s[left]);
			maxLen = max(maxLen, right - left);
			left++;
		} else {
			charSet.insert(s[right]);
			right++;
		}
	}

	maxLen = max(maxLen, right - left);
	return maxLen;
}

int main(){
	string s = "pwwkew";
	cout << lengthOfLongestSubstring(s) << '\n';
	return 0;
}
