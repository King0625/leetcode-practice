#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	unordered_set<string> wordSet(wordList.begin(), wordList.end());
	queue<string> todo;
	todo.push(beginWord);
	wordSet.erase(beginWord);

	int result = 1;
	while(!todo.empty()) {
		int size = todo.size();
		for(int i = 0; i < size; i++) {
			string word = todo.front();
			todo.pop();

			if(word == endWord) {
				return result;
			}

			wordSet.erase(word);
			int wordLen = word.size();
			for(int j = 0; j < wordLen; j++) {
				char c = word[j];
				for(int k = 0; k < 26; k++) {
					word[j] = 'a' + k;
					if(wordSet.find(word) != wordSet.end()) {
						todo.push(word);
					}
				}

				word[j] = c;
			}
		}
		result++;
	}

	return 0;
}

int main(){
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

	cout << ladderLength(beginWord, endWord, wordList);
	return 0;
}
