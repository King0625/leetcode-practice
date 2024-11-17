#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b)
{
  int a_index = a.size() - 1;
  int b_index = b.size() - 1;
  string result = "";
  int carry = 0;
  while (a_index >= 0 || b_index >= 0)
  {
    char a_char = a_index >= 0 ? a[a_index] : '0';
    char b_char = b_index >= 0 ? b[b_index] : '0';
    int sum = a_char + b_char + carry - 96;

    carry = sum / 2;
    int remain = sum % 2;
    char added_char = remain + 48;

    result = added_char + result;

    a_index--;
    b_index--;
  }

  if (carry == 1)
  {
    char remain_char = carry + 48;

    result = remain_char + result;
  }
  return result;
}

int main()
{
  string a = "1010";
  string b = "1011";
  cout << addBinary(a, b) << endl;
  return 0;
}