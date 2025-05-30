#include <iostream>

using namespace std;

int isVowel(char c) {
	switch(c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return 1;
		default:
			return 0;
	}
}

int maxVowels(string s, int k) {
	int max = INT_MIN;
	int count = 0;
	
	for(int i = 0; i <= s.size() - k; i++) {
		if(i == 0) {
			int first_frame_count = 0;
			for(int j = 0; j < k; j++) {
				first_frame_count += isVowel(s[j]);
			}
			count = first_frame_count;
		} else {
			count -= isVowel(s[i-1]);
			count += isVowel(s[i + k - 1]);
		}

		if(count > max) max = count;
	}

	return max;
}

int main() {
	string s = "leetcode";
	int k = 3;
	cout << maxVowels(s, k);

}
