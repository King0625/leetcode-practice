#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
	public:
		bool terminates = false;
		TrieNode* children[26];

		TrieNode() {
			for (auto& child : children) {
				child = nullptr;
			}
		}
};

class Trie {
	TrieNode* root;

	public:
	Trie() { root = new TrieNode(); }

	void insert(string word) {
		TrieNode* current = root;
		for (char c : word) {
			int index = c - 'a';
			if (!current->children[index]) {
				current->children[index] = new TrieNode();
			}

			current = current->children[index];
		}
		current->terminates = true;
	}

	bool search(string word) {
		TrieNode* current = root;
		for (char c : word) {
			int index = c - 'a';
			if (!current->children[index]) {
				return false;
			}
			current = current->children[index];
		}

		if (!current->terminates)
			return false;

		return true;
	}

	bool startsWith(string prefix) {
		TrieNode* current = root;
		for (char c : prefix) {
			int index = c - 'a';
			if (!current->children[index]) {
				return false;
			}
			current = current->children[index];
		}

		return true;
	}
};


int main(){
	return 0;
}
