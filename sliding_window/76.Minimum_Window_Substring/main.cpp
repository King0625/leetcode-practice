#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string minWindow(string s, string t) {
	string result = "";
	int t_len = t.size();
	int s_len = s.size();
	if(s_len < t_len) {
		return result;
	}

	if(s == t) {
		return s;
	}

	unordered_map<char, int> target_map;
	for(char c: t) {
		if(!target_map.count(c)){
			target_map[c] = 1;
		} else {
			target_map[c]++;
		}
	}

	int left_result = 0;
	int min_length = 0;

	for(int i = 0; i <= s_len - t_len; i++) {
		int left = i;
		int right = i;

		unordered_map<char,int> test_map(target_map);
		while(!test_map.empty()) {
			if(right >= s_len) {
				right = i;
				break;
			}
			if(test_map.count(s[right])) {
				if(--test_map[s[right]] == 0) {
					test_map.erase(s[right]);
				}
			}

			right++;
		}
		if(right - left != 0) {
			if(min_length == 0 || right - left < min_length) {
				min_length = right - left;
				left_result = left;
			} 
		}
	}

	if(min_length != 0) {
		result = s.substr((size_t)left_result, (size_t)min_length);
	}

	return result;

}


int main(){
	string s = "abc";
	string t = "b";
	string result = minWindow(s, t);
	cout << result << "\n";
}
