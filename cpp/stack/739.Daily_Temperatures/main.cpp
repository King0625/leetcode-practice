#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
	vector<int> results(temperatures.size(), 0);

	stack<int> mono;
	mono.push(0);

	for(int i = 1; i < temperatures.size(); i++) {
		while(!mono.empty() && temperatures[mono.top()] < temperatures[i]) {
			int topIndex = mono.top();
			mono.pop();
			results[topIndex] = i - topIndex;
		}
		mono.push(i);
	}

	return results;
}

int main(){
	vector<int> temperatures = {73,74,75,71,69,72,76,73};
	vector<int> result = dailyTemperatures(temperatures);

	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
}
