#include <iostream>
#include <map>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
	map<char, int> magazine_map;
	for(char letter: magazine)
	{
		if(magazine_map.count(letter) == 0)
		{
			magazine_map[letter] = 1;
		}
		else
		{
			magazine_map[letter]++;
		}
	}

	for(char c: ransomNote)
	{
		if(magazine_map.count(c) == 0 || magazine_map[c] == 0)
		{
			return false;
		}
		else
		{
			magazine_map[c]--;
		}
	}

	return true;
}

int main()
{
	string ransomNote = "aa";
	string magazine = "aab";
	string result = canConstruct(ransomNote, magazine) ? "true": "false";

	cout << result << "\n";


	return 0;
}
