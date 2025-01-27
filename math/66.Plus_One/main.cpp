#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
	int length = digits.size();
	int index = length - 1;
	digits[index] = (digits[index] + 1) % 10;
	bool hasCarry = digits[index] == 0;

	while(hasCarry && index > 0) {
		index--;
		digits[index] = (digits[index] + 1) % 10;
		hasCarry = digits[index] == 0;
	}

	if(index == 0 && hasCarry) {
		digits.push_back(0);
		digits[0] = 1;
	}

	return digits;
}

int main(){
	vector<int> digits = {9,8,9};
	vector<int> result = plusOne(digits);
	for(int val: result) {
		cout << val << ' ';
	}

	return 0;
}
