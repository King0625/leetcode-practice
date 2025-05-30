#include <iostream>
#include <vector>

using namespace std;

bool isPrefixAndSuffix(string s1, string s2) {
	int len1 = s1.size();
	int len2 = s2.size();
	if(len1 > len2) return false;
	for(int i = 0; i < len1; i++) {
		if(s1[i] != s2[i]) return false;
	}

	for(int j = 0; j < len1; j++) {
		if(s1[len1-1-j] != s2[len2-1-j]) return false;
	}

	return true;
}

int countPrefixSuffixPairs(vector<string>& words) {
	int result = 0;
	int len = words.size();
	for(int i = 0; i < len; i++) {
		for(int j = i+1; j < len; j++) {
			if(isPrefixAndSuffix(words[i], words[j])) {
				result++;
			}
		}
	}

	return result;
}

int main(){
	return 0;
}
