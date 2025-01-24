#include <iostream>
#include <vector>

using namespace std;

int prefixCount(vector<string>& words, string pref) {
	int count = 0;
	int prefLen = pref.size();
	for (string s : words) {
		int wordLen = s.size();
		if(wordLen < prefLen) continue;

		if (s.substr(0, prefLen) == pref) {
			count++;
		}
	}

	return count;
}

int main(){
	vector<string> words = {"pay","attention","practice","attend"};
	string pref = "at";
	cout << prefixCount(words, pref);
}
