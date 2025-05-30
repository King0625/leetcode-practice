#include <iostream>
#include <vector>

using namespace std;

bool gotCycle(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
	visited[node] = true;
	recStack[node] = true;

	for(int neighbor: adj[node]) {
		if(!visited[neighbor] && gotCycle(neighbor, adj, visited, recStack)) {
			return true;
		} else if(recStack[neighbor]) {
			return true;
		}
	}

	recStack[node] = false;
	return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	vector<vector<int>> adj(numCourses);
	for(vector<int> prerequisite: prerequisites) {
		int from = prerequisite[1];
		int to = prerequisite[0];
		adj[from].push_back(to);
	}
	vector<bool> visited(numCourses, false);
	vector<bool> recStack(numCourses, false);

	for(int i = 0; i < numCourses; i++) {
		if(!visited[i]) {
			if(gotCycle(i, adj, visited, recStack)) {
				return false;
			}
		}
	}
	
	return true;
}

int main(){
	int numCourses = 2;
	vector<vector<int>> prerequisites = {
		{1,0},{0,1}
	};

	if(canFinish(numCourses, prerequisites)) {
		cout << "Yes" << '\n';
	}
	return 0;
}
