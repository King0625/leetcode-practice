#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
	int num_len = numbers.size();
	int left = 0;
	int right = num_len - 1;
	while(left < right)
	{
		int total = numbers[left] + numbers[right];
		if(total > target){
			right--;
		} else if (total < target) {
			left++;
		} else {
			return {left+1, right+1};
		}
	}

	return {-1,-1};
}

int main()
{
	vector<int> numbers = {-10,-8,-2,1,2,5,6};
	int target = 0;
	vector<int> result = twoSum(numbers, target);
	for(int i: result)
	{
		cout << i << " ";
	}
	cout << "\n";
}
