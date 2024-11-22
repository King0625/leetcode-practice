#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int trailingZeroes(int n)
{
  int zero_count = 0;
  // zero comes from 5 * 2;
  for (int i = 5; n / i >= 1; i *= 5)
  {
    zero_count += n / i;
  }
  return zero_count;
}

int main()
{
  int result = trailingZeroes(30);
  // cout << result << "\n";
}