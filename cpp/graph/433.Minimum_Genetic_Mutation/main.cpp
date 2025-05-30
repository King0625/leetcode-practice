#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;


int minMutation(string startGene, string endGene, vector<string>& bank) {
	unordered_set<string> bankSet(bank.begin(), bank.end());

	if(!bankSet.count(endGene)) {
		return -1;
	}

	vector<char> bases ={'A', 'T', 'C', 'G'};

	queue<string> q;
	unordered_set<string> visited;

	int count = 0;

	q.push(startGene);
	visited.insert(startGene);

	while(!q.empty()) {
		int size = q.size();
		for(int i = 0; i < size; i++) {
			string s = q.front();
			q.pop();

			if(s == endGene) return count;

			for(int j = 0; j < 8; j++) {
				char base = s[j];

				for(int k = 0; k < 4; k++) {
					s[j] = bases[k];
					if(!visited.count(s) && bankSet.count(s)) {
						q.push(s);
						visited.insert(s);
					}
				}

				s[j] = base;
			}
		}

		count++;
	}


	return -1;
}


int main(){
	string startGene = "AACCGGTT";
	string endGene = "AAACGGTA";
	vector<string> bank = {
		"AACCGGTA","AACCGCTA","AAACGGTA"
	};

	cout << minMutation(startGene, endGene, bank) << '\n';
	return 0;
}
