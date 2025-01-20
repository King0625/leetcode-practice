#include <iostream>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) {
	int lenS = s.size();
	int lenT = t.size();
	if(lenS != lenT) return false;

	unordered_map<char,int> wordMap;

	for(char c: s) {
		if(!wordMap.count(c)) {
			wordMap[c] = 1;
		} else {
			wordMap[c]++;
		}
	}

	for(char c: t) {
		if(!wordMap.count(c)) {
			return false;
		}

		wordMap[c]--;
		if(wordMap[c] == 0) {
			wordMap.erase(c);
		}
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
