#include <iostream>
#include <vector>

using namespace std;

int largestAltitude(vector<int>& gain) {
	int size = gain.size();
	
	int largest = 0;

	int sum = 0;

	for(int i = 0; i < size; i++) {
		sum += gain[i];
		largest = max(sum, largest);
	}

	return largest;
}


int main(){
	vector<int> gain = {-4,-3,-2,-1,4,3,2};
	cout << largestAltitude(gain) << '\n';
}
