#include <iostream>

using namespace std;

int rangeBitwiseAnd(int left, int right) {
	int shifted = 0;

	while(left != right) {
		left >>= 1;
		right >>= 1;
		shifted++;
	}

	return (left << shifted);
}

int main(){
	int left = 1;
	int right = 2147483647;
	cout << rangeBitwiseAnd(left, right) << '\n';
}
