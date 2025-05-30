#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<string> summaryRanges(vector<int> &nums)
{
  vector<string> results;
  if (nums.size() == 0)
  {
    return results;
  }

  int left_num = nums[0];
  int last_num = nums[0];

  if (nums.size() > 1)
  {
    for (int i = 1; i < nums.size(); i++)
    {
      if (nums[i] - 1 > last_num)
      {
        string result = last_num == left_num ? to_string(last_num) : to_string(left_num) + "->" + to_string(last_num);
        results.push_back(result);
        left_num = nums[i];
      }
      last_num = nums[i];
    }
  }

  string last_result = left_num == last_num ? to_string(left_num) : to_string(left_num) + "->" + to_string(last_num);
  results.push_back(last_result);

  return results;
}

int main()
{
  vector<int> nums = {2, 3, 4, 7, 9};
  vector<string> results = summaryRanges(nums);
  for (string s : results)
  {
    cout << s << "\n";
  }
}