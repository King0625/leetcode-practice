#include <iostream>
#include <stack>

using namespace std;

string sanitation(string s) {
	string result = "";
	for(char c: s) {
		if(c == ' ')
			continue;

		result.push_back(c);
	}

	return result;
}

int calculate(string s) {
	int result = 0;

	stack<char> st;

	int size = s.size();

	for(int i = 0; i < size; i++) {
		cout << s[i] << '\n';

	}
     
	return result;
}

int main(){
	string s = " 2-1 + 2 ";
	string sanitized = sanitation(s);

	cout << calculate(sanitized) << '\n';
	return 0;
}
