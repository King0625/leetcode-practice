#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> minOperations(string boxes) {
	int length = boxes.size();
	vector<int> prefixes(length, 0);

	for(int i = 0; i < length; i++) {
		int moves = 0;
		for(int j = 0; j < length; j++) {
			if(boxes[j] == '1') {
				moves += abs(i - j);
			}
		}
		prefixes[i] = moves;
	}

	return prefixes;
}

int main(){
	string boxes = "001011";
	vector<int> result = minOperations(boxes);
	for(int val: result) {
		cout << val << ' ';
	}
}
