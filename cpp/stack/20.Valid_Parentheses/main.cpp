#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isValid(string s)
{
  if (s[0] == ')' || s[0] == '}' || s[0] == ']')
    return false;

  if (s.size() % 2 != 0)
  {
    return false;
  }

  map<char, char> bracket_map;
  bracket_map['('] = ')';
  bracket_map[')'] = '(';
  bracket_map['{'] = '}';
  bracket_map['}'] = '{';
  bracket_map['['] = ']';
  bracket_map[']'] = '[';

  vector<char> char_stack;
  char_stack.push_back(s[0]);
  for (int i = 1; i < s.size(); i++)
  {
    char c = s[i];
    bool is_same_direction = (c == '(' || c == '{' || c == '[');

    switch (c)
    {
    case '(':
    case '{':
    case '[':

      if (char_stack.size() == 0)
      {
        char_stack.push_back(c);
      }
      else if (char_stack.back() == bracket_map[c])
      {
        char_stack.pop_back();
      }
      else if (char_stack.back() != bracket_map[c] && is_same_direction)
      {
        char_stack.push_back(c);
      }
      else
      {
        return false;
      }
      break;
    case ')':
    case '}':
    case ']':
      if (char_stack.size() == 0 || char_stack.back() != bracket_map[c])
      {
        return false;
      }
      else
      {
        char_stack.pop_back();
      }
      break;
    }
  }
  return char_stack.size() == 0;
}

int main()
{
  string s = "([])";
  string result = isValid(s) ? "true" : "false";
  cout << result << "\n";
}