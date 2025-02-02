#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(int x) {
	if(x < 0) return false;
	
	int dividend = 10;
	vector<int> digits;
	while(x != 0) {
		digits.push_back(x % dividend);
		x /= 10;
	}

	int left = 0, right = digits.size() - 1;

	while(left <= right) {
		if(digits[left] != digits[right]) {
			return false;
		}
		left++;
		right--;
	}
	return true;
	
}

int main(){
	int x = -11;
	if(isPalindrome(x)) {
		cout << "True";
	}
}
