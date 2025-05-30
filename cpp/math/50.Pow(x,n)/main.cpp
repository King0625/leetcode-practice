#include <iostream>
#include <cmath>

using namespace std;

double myPow(double x, long n){
	if(n < 0) {
		x = 1/x;
	}


	double result = 1.0;
	while(n) {
		if(n % 2){
			result *= x;
		}
		x *= x;
		n /= 2;
	}

	return result;
}


int main(){
	double x = 2.00000;
	int n = 10;

	cout << myPow(x, n) << "\n";
}
