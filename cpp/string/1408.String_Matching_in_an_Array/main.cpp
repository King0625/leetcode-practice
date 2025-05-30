#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> stringMatching(vector<string>& words) {
	vector<string> result;
	int wordCounts = words.size();
	for(int i = 0; i < wordCounts; i++) {
		bool isSubstr = false;
		for(int j = 0; j < wordCounts; j++) {
			if(!isSubstr && j != i && words[i].size() < words[j].size()) {
				size_t found = words[j].find(words[i]);
				if(found != string::npos) {
					result.push_back(words[i]);
					isSubstr = true;
				}
			}
		}
	}

	return result;
}


int main(){
	vector<string> words = {"mass","as","hero","superhero"};
	vector<string> result = stringMatching(words);
	for(string s: result) {
		cout << s << ' ';
	}
	return 0;
}
