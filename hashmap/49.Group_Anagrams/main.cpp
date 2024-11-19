#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
  vector<vector<string>> result = {};
  map<vector<char>, vector<string>> anagrams = {};
  vector<char> char_vector = {};
  for (string str : strs)
  {
    for (char c : str)
    {
      char_vector.push_back(c);
    }

    sort(char_vector.begin(), char_vector.end());

    if (!anagrams.count(char_vector))
    {
      anagrams[char_vector] = {str};
    }
    else
    {
      anagrams[char_vector].push_back(str);
    }
    char_vector.clear();
  }

  if (anagrams.size() == 0)
  {
    result.push_back({{""}});
  }
  else
  {
    for (const auto &el : anagrams)
    {
      result.push_back(el.second);
    }
  }

  return result;
}

int main()
{
  vector<string> strs = {""};
  groupAnagrams(strs);
  return 0;
}