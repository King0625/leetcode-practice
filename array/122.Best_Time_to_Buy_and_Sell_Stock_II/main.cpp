#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	int profit = 0;
	int days = prices.size();

	for(int i = 1; i < days; i++) {
		int current = prices[i];
		int prev = prices[i-1];
		if(current > prev) {
			profit += current - prev;
		}
	}

	return profit;
}

int main(){
	vector<int> prices = {7,1,5,3,6,4};
	cout << maxProfit(prices);
	return 0;
}
