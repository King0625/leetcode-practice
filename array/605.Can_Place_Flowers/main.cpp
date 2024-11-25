#include <iostream>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
	if(flowerbed.size() == 1 && flowerbed[0] == 0) {
		flowerbed[0] = 1;
		n--; 
		return n<=0;
	} else {
		if(flowerbed[0] == 0 && flowerbed[1] == 0) {
			flowerbed[0] = 1;
			n--;
		}
	}



	for(int i = 1; i < flowerbed.size() - 1; i++) {
		if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0 && flowerbed[i] == 0) {
			flowerbed[i] = 1;
			n--;	
		}
	}


	if(flowerbed[flowerbed.size() - 1] == 0 && flowerbed[flowerbed.size() - 2] == 0) {
		flowerbed[flowerbed.size() - 1] = 1;
		n--;
	}

	return n <= 0;
}

int main(){
	vector<int> flowerbed = {1,0,1,0,1,0,1};
	int n = 1;
	string result = canPlaceFlowers(flowerbed, n) ? "true" : "false";
	cout << result << "\n";
}
