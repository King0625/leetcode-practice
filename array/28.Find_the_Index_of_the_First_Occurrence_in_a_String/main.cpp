#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int strStr(string haystack, string needle) {
  int result = -1;
  int len_haystack = haystack.length();
  int len_needle = needle.length();
  if (len_haystack >= len_needle) {
    for (int i = 0; i <= len_haystack - len_needle; i++) {
      string substring_from_haystack = haystack.substr(i, len_needle);
      if (substring_from_haystack == needle) {
        result = i;
        break;
      }
    }
  }

  return result;
}

int main() {
  string haystack = "leetcode";
  string needle = "leeto";
  cout << strStr(haystack, needle) << endl;
  return 0;
}