#include <iostream>
#include <unordered_map>

using namespace std;

void backtrack(unordered_map<char, string> digitToLetters, vector<string>& results, string comb, string digits, int index) {
	if(comb.size() == digits.size()) {
		results.push_back(comb);
		return;
	}

	string letters = digitToLetters[digits[index]];
	for(int i = 0; i < letters.size(); i++) {
		char letter = letters[i];
		backtrack(digitToLetters, results, comb + letter, digits, index + 1);
	}
}

vector<string> letterCombinations(string digits) {
	unordered_map<char, string> digitToLetters = {
		{'2', "abc"},
		{'3', "def"},
		{'4', "ghi"},
		{'5', "jkl"},
		{'6', "mno"},
		{'7', "pqrs"},
		{'8', "tuv"},
		{'9', "wxyz"}
	};

	vector<string> results;
	if(digits.empty()) return results;

	backtrack(digitToLetters, results, "", digits, 0);
	return results;
}


int main(){
	string digits = "7";
	vector<string> results = letterCombinations(digits);
	for(string result: results) {
		cout << result << ' ';
	}

	cout << '\n';
}
