#include <iostream>
#include <string>

using namespace std;

int getLucky(string s, int k) {
	string firstTrans = "";
	for(char c: s) {
		string result = to_string(c - 96);
		firstTrans += result;
	}

	int firstTransNum = 0;
	for(char c: firstTrans) {
		firstTransNum += c - 48;
	}

	int result = firstTransNum;

	for(int i = 1; i < k; i++) {
		int remainders = 0;
		while(result > 0) {
			remainders += result % 10;
			result /= 10;
		}

		result = remainders;
	}

	return result;
}


int main(){
	string s = "zbax";
	int k = 2;
	cout << getLucky(s, k) << '\n';
}
