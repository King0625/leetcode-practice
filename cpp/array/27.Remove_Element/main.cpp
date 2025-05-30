#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
  int result = 0;
  if (nums.size() != 0)
  {
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] != val)
      {
        nums[result] = nums[i];
        result++;
      }
    }
  }

  return result;
}

int main()
{
  vector<int> nums = {3, 2, 2, 3};
  int val = 3;
  int result = removeElement(nums, val);
  cout << result << "\n";
  return 0;
}