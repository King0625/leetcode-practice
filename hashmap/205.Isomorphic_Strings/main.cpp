#include <iostream>
#include <map>

using namespace std;

bool isIsomorphic(string s, string t) {
	map<char,int> char_map_s;
	map<char,int> char_map_t;
	for(int i = 0; i < s.size(); i++) {
		if(char_map_s.count(s[i]) == 0) {
			char_map_s[s[i]] = i;
		}
		if(char_map_t.count(t[i]) == 0) {
			char_map_t[t[i]] = i;
		}

		if(char_map_s[s[i]] != char_map_t[t[i]]) {
			return false;
		}
	}

	return true;
}

int main(){
	string s = "babc";
	string t = "baba";
	string result = isIsomorphic(s, t) ? "true":"false";

	cout << result << "\n";
	return 0;
}
