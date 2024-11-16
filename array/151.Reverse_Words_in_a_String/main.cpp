#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::string reverseWords(std::string s)
{
  std::vector<std::string> words;
  std::stringstream ss(s);
  std::string temp;
  while (std::getline(ss, temp, ' '))
  {
    words.push_back(temp);
  }
  std::string result = "";

  for (int i = words.size() - 1; i >= 0; i--)
  {
    std::cout << words[i] << "|" << std::endl;
    std::string blank = " ";
    if (words[i] != "")
    {
      result += words[i] + blank;
    }
  }
  if (result.back() == ' ')
  {
    result.pop_back();
  }
  return result;
}

int main()
{
  std::string s = "  hello world  ";
  std::cout << reverseWords(s) << "|" << std::endl;
  return 0;
}