#include <iostream>
#include <vector>

using namespace std;

bool isAnagram(string s, string t) {
	int lenS = s.size();
	int lenT = t.size();
	if(lenS != lenT) return false;

	vector<int> wordMap(26,0);

	for(char c: s) {
		wordMap[c - 'a']++;
	}

	for(char c: t) {
		if(wordMap[c - 'a'] == 0) {
			return false;
		}

		wordMap[c - 'a']--;
	}

	return true;
}


int main(){
	string s = "rat";
	string t = "car";
	if(isAnagram(s,t)) {
		cout << "Yes";
	}
}
