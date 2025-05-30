#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

char getMirror(char c) {
	return 'z' - c + 'a';
}

long long calculateScore(string s) {
	int length = s.size();
	long long score = 0;

	unordered_map<char, int> checked;
	vector<bool> marked(length, false);

	for(int i = 0; i < length; i++) {
		int j = i - 1;
		while(j >= 0) {
			if(getMirror(s[i]) == s[j] && !marked[i] && !marked[j]) {
				checked[s[i]] = i-j;
				checked[s[j]] = i-j;
				marked[i] = true;
				marked[j] = true;
				score += i-j;
				break;
			}

			j--;
		}

	}

	return score;
}

int main(){
	string s = "eockppxdqclkhjgvnw";
	cout << calculateScore(s);
	return 0;
}
