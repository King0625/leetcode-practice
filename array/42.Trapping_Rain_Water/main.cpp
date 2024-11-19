#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calulate_trap(vector<int> &trap_area, int left_highest, int right_highest)
{
  int trap_count = 0;
  int second_highest = min(left_highest, right_highest);
  for (int i = 0; i < trap_area.size() - 1; i++)
  {
    if (second_highest - trap_area[i] >= 0)
      trap_count += second_highest - trap_area[i];
  }
  trap_area.clear();
  return trap_count;
}

int trap(vector<int> &height)
{
  if (height.size() == 1)
    return 0;

  int last_height = height[0];
  int left_highest = last_height;
  int result = 0;
  int right_highest = -1;
  vector<int> trap_area = {};

  for (int i = 1; i < height.size(); i++)
  {
    // 1.
    if (last_height <= height[i])
    {
      if (trap_area.size() == 0)
      {
        left_highest = height[i];
      }
      else
      {
        right_highest = height[i];
        trap_area.push_back(height[i]);
      }
    }

    // 2.
    if (last_height > height[i])
    {
      if (right_highest != -1 && left_highest <= right_highest)
      {
        // start to calulate the trap, and renew a new trap_area
        result += calulate_trap(trap_area, left_highest, right_highest);
        left_highest = right_highest;
        right_highest = -1;
      }

      trap_area.push_back(height[i]);
    }

    last_height = height[i];

    if (i == height.size() - 1)
    {
      result += calulate_trap(trap_area, left_highest, right_highest);
    }
  }

  return result;
}

int main()
{
  vector<int> heights = {5, 4, 1, 2};
  cout << trap(heights) << endl;
  return 0;
}