#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool wordPattern(string pattern, string s)
{
  vector<string> words;
  string word = "";
  for (char c : s)
  {
    if (c == ' ')
    {
      words.push_back(word);
      word.clear();
    }
    else
    {
      word += c;
    }
  }
  words.push_back(word);
  for (string w : words)
  {
    cout << w << " ";
  }

  if (pattern.size() != words.size())
    return false;

  map<char, string> pattern_map;

  for (int i = 0; i < pattern.size(); i++)
  {
    if (pattern_map.count(pattern[i]) == 0)
    {
      for (const auto &kv : pattern_map)
      {
        if (kv.second == words[i])
        {
          return false;
        }
      }
      pattern_map[pattern[i]] = words[i];
    }
    else if (pattern_map.count(pattern[i]) > 0 && words[i] != pattern_map[pattern[i]])
    {
      return false;
    }
  }

  return true;
}
int main()
{
  string pattern = "aaa";
  string s = "aa aa aa aa";
  bool result = wordPattern(pattern, s);
  string output = result ? "true" : "false";
  cout << "\n"
       << output << "\n";
}