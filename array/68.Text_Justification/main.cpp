#include <iostream>
#include <vector>

using namespace std;

string formChunk(vector<string>& words, int maxWidth, int index, int wordLength, int wordCount) {
	string chunk = "";
	if(wordCount == 1) {
		chunk += words[index - 1] + string(maxWidth - wordLength, ' ');
	} else {
		int spaceCount = maxWidth - wordLength;
		int remainSpaceLength = spaceCount % (wordCount - 1);
		for(int i = 0; i < wordCount - 1; i++) {
			int spaceLength = spaceCount / (wordCount - 1);
			if(remainSpaceLength > 0) {
				spaceLength++;
				remainSpaceLength--;
			}
			chunk += words[index - wordCount + i] + string(spaceLength, ' ');
		}

		chunk += words[index - 1];
	}

	return chunk;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
	vector<string> chunks;

	int wordCount = 1;
	int wordLength = words[0].size();

	for(int i = 1; i < words.size(); i++) {
		wordCount++;
		wordLength += words[i].size();
		if(wordLength > maxWidth || (maxWidth - wordLength) / (wordCount - 1) < 1) {
			wordLength -= words[i].size();
			wordCount--;
			string chunk = formChunk(words, maxWidth, i, wordLength, wordCount);
			chunks.push_back(chunk);
			wordCount = 1;
			wordLength = words[i].size();
		}
	}

	string lastChunk = "";
	int spaceCount = maxWidth - wordLength;
	for(int j = 0; j < wordCount; j++) {
		lastChunk += words[words.size() - wordCount + j];
		if(j == wordCount - 1) {
			lastChunk += string(spaceCount, ' ');
		} else {
			lastChunk += ' ';
			spaceCount--;
		}
	}
	chunks.push_back(lastChunk);
	
	return chunks;
}

int main(){
	vector<string> words = {"What","must","be","acknowledgment","shall","be"};
	int maxWidth = 16;
	vector<string> result = fullJustify(words, maxWidth);
	for(string s: result) {
		cout << s << "|\n";
	}
}
