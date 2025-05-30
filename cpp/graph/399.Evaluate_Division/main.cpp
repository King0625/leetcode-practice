#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
	unordered_set<string> variables;

	for(vector<string> &eq: equations) {
		for(string &s: eq) {
			variables.insert(s);
		}
	}

	for(string s: variables) {
		cout << s << ' ';
	}
	int length = queries.size();

	vector<double> result(length, 0.0);

	return result;
}

int main(){
	vector<vector<string>> equations = {
		{"a","b"}, {"b","c"}, {"bc", "cd"}
	};

	vector<double> values = {1.5, 2.5, 5.0};
	vector<vector<string>> queries = {
		{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}
	};

	vector<double> result = calcEquation(equations, values, queries);
	for(double val: result) {
		cout << val << ' ';
	}
	return 0;
}
