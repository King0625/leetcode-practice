#include <iostream>

using namespace std;


int guessNumber(int n) {
	int low = 1;
	int high = n;
	int mid;
	while(low <= high) {
		mid = low + (high - low) / 2;
		if(guess(mid) == -1) {
			high = mid;	
		} else if(guess(mid) == 1) {
			low = mid + 1;
		} else {
			return mid;
		}
	}
	return 0;
}


int main(){
	return 0;

}
