#include <iostream>
#include <vector>
using namespace std;

// TODO: try to come up with extra solutions

void rotate(vector<int> &nums, int k)
{
  int len = nums.size();
  k %= len;

  for (int i = 0; i < k; i++)
  {
    int num_to_rotate = nums[len - 1];
    for (int j = len - 1; j > 0; j--)
    {
      nums[j] = nums[j - 1];
    }
    nums[0] = num_to_rotate;
  }
}

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5, 6};
  int k = 7;
  rotate(nums, k);

  for (int num : nums)
  {
    cout << num << " ";
  }

  return 0;
}