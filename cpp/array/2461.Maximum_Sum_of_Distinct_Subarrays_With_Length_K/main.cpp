#include <iostream>
#include <set>
using namespace std;

long long maximumSubarraySum(vector<int> &nums, int k)
{
  long long max = 0;
  set<int> sub_set = {};
  for (int i = 0; i <= nums.size() - k; i++)
  {
    for (int j = i; j < i + k; j++)
    {
      sub_set.insert(nums[j]);
    }

    if (sub_set.size() == k)
    {
      int result = 0;
      for (int el : sub_set)
      {
        result += el;
      }
      if (result > max)
      {
        max = result;
      }
    }
    sub_set.clear();
  }

  return max;
}

int main()
{
  int k = 3;
  vector<int> nums = {1, 1, 1, 7, 8, 9};
  cout << maximumSubarraySum(nums, 3) << "\n";
}