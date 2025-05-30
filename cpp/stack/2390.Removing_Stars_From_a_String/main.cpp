#include <iostream>

using namespace std;

string removeStars(string s) {
	string result = "";
	for(char c: s){
		if(c == '*') {
			result.pop_back();
		} else {
			result += c;
		}
	}

	return result;
}


int main(){
	string s = "leet**cod*e";
	string result = removeStars(s);
	cout << result << "\n";
}
