#include <iostream>
#include <vector>

using namespace std;

int countOnes(int num) {
	int count = 0;
	while(num > 0) {
		if(num & 1) {
			count++;
		}
		num >>= 1;
	}

	return count;
}

vector<int> countBits(int n) {
        vector<int> results;

	for(int i = 0; i <= n; i++) {
		int count = countOnes(i);
		results.push_back(count);
	}

	return results;
}

int main(){
	int n = 5;
	vector<int> results = countBits(n);
	for(auto &el: results) {
		cout << el << " ";
	}

}
