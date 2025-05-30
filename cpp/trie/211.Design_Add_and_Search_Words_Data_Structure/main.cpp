#include <iostream>

using namespace std;

class TrieNode {
	public:
		bool hasEnd = false;
		TrieNode* children[26];

		TrieNode() {
			for(auto& child: children) {
				child = nullptr;
			}
		}
};

class WordDictionary {
	public:
		TrieNode* root;

		WordDictionary() {
			root = new TrieNode(); 
		}

		void addWord(string word) {
			TrieNode* current = root;
			for(char c: word) {
				int index = c - 'a';
				if(!current->children[index]) {
					current->children[index] = new TrieNode();
				}

				current = current->children[index];
			}

			current->hasEnd = true;
		}

		bool searchHelper(TrieNode* current, string word) {
			int length = word.size();
			for(int i = 0; i < length; i++) {
				char c = word[i];
				if(c != '.') {
					if(!current->children[c - 'a']) {
						return false;
					}

					current = current->children[c - 'a'];
				} else {
					TrieNode* temp = current;
					for(int j = 0; j < 26; j++) {
						current = temp->children[j];
						if(!current) continue;

						if(searchHelper(current, word.substr(i+1))) {
							return true;
						}
					}

					return false;
				}
			}

			return current->hasEnd;
		}

		bool search(string word) {
			return searchHelper(root, word);
		}
};


int main(){
	WordDictionary* obj = new WordDictionary();
	obj->addWord("bad");
	obj->addWord("mad");
	obj->addWord("dad");
	obj->search("pad") ? cout << "Yes" << '\n' : cout << "No" << '\n';
	obj->search("ba") ? cout << "Yes" << '\n' : cout << "No" << '\n';
	obj->search(".ad") ? cout << "Yes" << '\n' : cout << "No" << '\n';
	obj->search("b..") ? cout << "Yes" << '\n' : cout << "No" << '\n';
}
