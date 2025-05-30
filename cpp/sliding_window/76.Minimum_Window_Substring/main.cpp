#include <iostream>
#include <vector>
#include <string>

using namespace std;

string minWindow(string s, string t) {
	int t_len = t.size();
	int s_len = s.size();
	if(s_len < t_len) {
		return "";
	}

	if(s == t) {
		return s;
	}

	vector<int> chars(128, 0);
	for(char c: t) {
		chars[c]++;
	}

	int count = t_len;
	int start = 0;
	int start_index = 0;
	int end = 0;
	int min_length = INT_MAX;

	while(end < s_len) {
		if(chars[s[end++]]-- > 0) {
			count--;
		}

		while(count == 0) {
			if(end - start < min_length) {
				start_index = start;
				min_length = end - start;
			}

			if(chars[s[start++]]++ == 0) {
				count++;
			}
		}
	}
	
	return min_length == INT_MAX ? "" : s.substr(start_index, min_length);
}


int main(){
	string s = "ADOBECODEBANC";
	string t = "ABC";
	string result = minWindow(s, t);
	cout << result << "\n";
}
