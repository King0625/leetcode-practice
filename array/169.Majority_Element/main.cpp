#include <iostream>
#include <map>
#include <vector>

using std::cout;
using std::map;
using std::vector;

int majorityElement(vector<int>& nums) {
  map<int, int> num_map;
  for (int num : nums) {
    if (num_map[num] == 0) {
      num_map[num] = 1;
    } else {
      num_map[num]++;
    }
  }

  int counts = INT32_MIN;
  int result = INT32_MIN;
  for (const auto& m : num_map) {
    if (m.second > counts) {
      counts = m.second;
      result = m.first;
    }
  }

  return result;
}

int main() {
  vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
  int result = majorityElement(nums);
  cout << result;
  return 0;
}