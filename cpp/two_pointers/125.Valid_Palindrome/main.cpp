#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::replace;
using std::stoi;
using std::string;

bool isPalindrome(string s) {
  string sanitized;
  for (int i = 0; i < s.size(); i++) {
    if (isalnum(s[i])) {
      sanitized += tolower(s[i]);
    }
  }

  int middle_index = (int)round(sanitized.size() / 2);
  for (int j = 0; j < middle_index; j++) {
    if (sanitized[j] != sanitized[sanitized.size() - 1 - j]) {
      return false;
    }
  }

  return true;
}

int main() {
  string s = "ab_a";
  cout << isPalindrome(s);
}