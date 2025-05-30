#include <iostream>

using namespace std;

bool isSubsequence(string s, string t) {
	int indexOfT = 0, indexOfS = 0;
	while(indexOfT < t.size() && indexOfS <= s.size() - 1) {
		if(t[indexOfT] == s[indexOfS]) {
			indexOfS++;
		}

		indexOfT++;
	}

	return indexOfS == s.size();
}

int main(){
	string s = "abc";
	string t = "ahbgdc";
	if(isSubsequence(s, t)) {
		cout << "Yes" << "\n";
	}
	return 0;
}
