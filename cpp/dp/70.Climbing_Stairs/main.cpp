#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n)
{
  vector<int> solutions;
  solutions.push_back(1);
  solutions.push_back(1);

  for (int i = 2; i <= n; i++)
  {
    solutions.push_back(solutions[i - 1] + solutions[i - 2]);
  }
  return solutions[n];
}

int main()
{
  int n = 2;
  int result = climbStairs(n);
  cout << result << "\n";
  return 0;
}