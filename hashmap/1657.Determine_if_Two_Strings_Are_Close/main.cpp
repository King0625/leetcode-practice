#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

map<char, int> getWordComposition(string word) {
	map<char, int> word_map;

	for(char c: word){
		if(!word_map.count(c)) {
			word_map[c] = 1;
		} else {
			word_map[c]++;
		}
	}

	return word_map;
}

bool closeStrings(string word1, string word2) {
		map<char, int> word1_map = getWordComposition(word1);
		map<char, int> word2_map = getWordComposition(word2);

		set<char> word1_set, word2_set;
		vector<int> word1_freq, word2_freq;

		for(auto &km1: word1_map) {
			word1_set.insert(km1.first);
			word1_freq.push_back(km1.second);
		}

		for(auto &km2: word2_map) {
			word2_set.insert(km2.first);
			word2_freq.push_back(km2.second);
		}

		if(word1_set != word2_set || word1_freq.size() != word2_freq.size())
			return false;

		sort(word1_freq.begin(), word1_freq.end());
		sort(word2_freq.begin(), word2_freq.end());
		
		for(int i = 0; i < word1_freq.size(); i++) {
			if(word1_freq[i] != word2_freq[i])
				return false;
		}

		return true;
}


int main(){
	string word1 = "aaabbbbccddeeeeefffff";
	string word2 = "aaaaabbcccdddeeeeffff";

	bool result = closeStrings(word1, word2);
	
	if(result) cout << "true";
}
