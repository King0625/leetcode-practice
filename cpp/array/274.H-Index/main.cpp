#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::sort;
using std::vector;

int hIndex(vector<int>& citations) {
  // [11,15]
  sort(citations.begin(), citations.end());
  int all_citation_count = citations.size();
  int count = all_citation_count;
  for (int i = 0; i < all_citation_count; i++) {
    if (citations[i] < count) {
      count--;
    }
  }
  return count;
}

int main() {
  vector<int> nums = {3, 0, 6, 1, 5};
  cout << hIndex(nums) << endl;
  return 0;
}