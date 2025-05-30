#include <iostream>
#include <vector>

using namespace std;

bool isPrerequisite(int from, int to, vector<vector<int>>& graph, vector<bool>& visited) {
	if(from == to) {
		return true;
	}

	visited[from] = true;

	for(int neighbor: graph[from]) {
		if(!visited[neighbor]) {
			if(isPrerequisite(neighbor, to, graph, visited)) {
				return true;
			}
		}
	}

	return false;
}

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
	vector<vector<int>> graph(numCourses);
	
	for(vector<int> prerequisite: prerequisites) {
		graph[prerequisite[0]].push_back(prerequisite[1]);
	}

	int queryCount = queries.size();

	vector<bool> result(queryCount, false);

	for(int i = 0; i < queryCount; i++) {
		vector<bool> visited(numCourses, false);
		result[i] = isPrerequisite(queries[i][0], queries[i][1], graph, visited);
	}

	return result;
}


int main(){
	int numCourses = 2;
	vector<vector<int>> prerequisites = {
		{1,2},{1,0},{2,0}
	};
	vector<vector<int>> queries = {
		{1,0},{1,2}
	};

	vector<bool> result = checkIfPrerequisite(numCourses, prerequisites, queries);

	for(bool val: result) {
		if(val) {
			cout << "Yes";
		} else {
			cout << "No";
		}

		cout << ' ';
	}

	return 0;
}
