#include <iostream>
#include <queue>

using namespace std;

string predictPartyVictory(string senate) {
	queue<int> radiant, dire;
	int length = senate.size();
	for(int i = 0; i < length; i++) {
		senate[i] == 'R' ? radiant.push(i) : dire.push(i);
	}

	while(!radiant.empty() && !dire.empty()) {
		if(radiant.front() < dire.front()) {
			radiant.push(length++);
		} else {
			dire.push(length++);
		}

		radiant.pop();
		dire.pop();
	}

	return !radiant.empty() ? "Radiant" : "Dire";
}

int main(){
	string senate = "DDRRR";
	string result = predictPartyVictory(senate);
	cout << result << '\n';
}
