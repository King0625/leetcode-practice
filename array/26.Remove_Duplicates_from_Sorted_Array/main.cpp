#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int removeDuplicates(vector<int>& nums) {
  if (nums.size() == 0) return 0;
  int i = 1;
  for (int j = 1; j < nums.size(); j++) {
    if (nums[j] != nums[j - 1]) {
      nums[i] = nums[j];
      i++;
    }
  }

  return i;
}

// test
int main() {
  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int result = removeDuplicates(nums);
  cout << result << endl;
}