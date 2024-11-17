#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
  int length = -1;
  int left = 0;
  int right = 0;
  int count = 0;
  while (right < nums.size())
  {
    count += nums[right];
    if (count >= target)
    {
      int new_length = right - left + 1;
      if (length == -1 || length > new_length)
      {
        length = new_length;
      }
      left++;
      right = left;
      count = 0;
    }
    else
    {
      right++;
    }
  }

  if (left == 0 && right == nums.size())
    return 0;

  return length;
}
int main()
{
  int target = 7;
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  cout << minSubArrayLen(target, nums) << endl;
  return 0;
}