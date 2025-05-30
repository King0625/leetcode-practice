#include <iostream>
#include <vector>

using namespace std;

int tribonacci(int n) {
	int temp[3] = {0,1,1};
	if(n < 3) {
		return temp[n];
	}

	for(int i = 3; i <= n; i++) {
		int result = temp[0] + temp[1] + temp[2];
		temp[0] = temp[1];
		temp[1] = temp[2];
		temp[2] = result;
	}

	return temp[2];
}

int main(){
	int n = 5;
	cout << tribonacci(n) << '\n';
}
