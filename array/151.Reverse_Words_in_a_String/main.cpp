#include <iostream>
#include <string>

using namespace std;

string reverseWords(string s)
{
  string result = "";
  string temp = "";
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == ' ')
    {
      if (temp != "")
      {
        result = " " + temp + result;
      }
      temp = "";
    }
    else
    {
      temp += s[i];
      if (i == s.size() - 1)
        result = temp + result;
    }
  }

  if (result[0] == ' ')
    result.erase(result.begin());

  return result;
}

int main()
{
  string s = "  hello world  ";
  cout << reverseWords(s) << "|" << endl;
  return 0;
}