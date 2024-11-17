#include <iostream>
#include <vector>
using namespace std;

int shortestSubarray(vector<int> &nums, int k)
{
  int length = -1;
  int left = 0;
  int count = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    left = i;
    while (left >= 0)
    {
      count += nums[left];
      if (count >= k)
      {
        int new_length = i - left + 1;
        if (length == -1 || length > new_length)
        {
          length = new_length;
        }

        count = 0;
      }
      left--;
    }
    count = 0;
  }

  return length;
}

int main()
{
  vector<int> nums = {1, 2};
  int k = 4;
  cout << shortestSubarray(nums, k) << endl;
  return 0;
}