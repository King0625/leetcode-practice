#include <iostream>
#include <vector>

using namespace std;

int candy(vector<int>& ratings) {
	int result = 0;
	int last_rating = ratings[0];

	vector<int> candies = {1};

	for(int i = 1; i < ratings.size(); i++) {
		if(last_rating == ratings[i]) {
			candies.push_back(1);
		} else if(last_rating < ratings[i]) {
			candies.push_back(candies[i-1] + 1);
		} else {
			candies.push_back(1);
			int last_index = i - 1;
			while(last_index >= 0){
				if(ratings[last_index] > ratings[last_index + 1] && candies[last_index] == candies[last_index+1]) {
					candies[last_index]++;
					last_index--;	
				} else {
					break;
				}
			}	
		}

		last_rating = ratings[i];
	}

	for(int candy: candies) {
		cout << candy << " ";
		result += candy;
	}
	return result;
}

int main()
{
	vector<int> ratings = {1,6,10,8,7,3,2};
	cout << candy(ratings) << "\n";
	return 0;
}
