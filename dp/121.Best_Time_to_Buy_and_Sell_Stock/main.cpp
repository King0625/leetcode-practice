#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
	int days = prices.size();
	int buy = prices[0];
	int profit = 0;
	for(int i = 1; i < days; i++) {
		if(prices[i] < buy) {
			buy = prices[i];
		} else {
			if(profit < prices[i] - buy) {
				profit = prices[i] - buy;
			}
		}
	}

	return profit;
}
int main(){
	vector<int> prices = {7,1,5,3,6,4};
	cout << maxProfit(prices) << '\n';
}
