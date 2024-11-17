#include <iostream>
using namespace std;
int lengthOfLastWord(string s)
{
  string result = "";
  for (int i = s.size() - 1; i >= 0; i--)
  {
    char c = s[i];
    if (c == ' ')
    {
      if (result.size() != 0)
      {
        break;
      }
      else
      {
        continue;
      }
    }
    result += c;
  }

  return result.size();
}
int main()
{
  string s = "   fly me   to   the moon  ";
  cout << lengthOfLastWord(s) << endl;
  return 0;
}