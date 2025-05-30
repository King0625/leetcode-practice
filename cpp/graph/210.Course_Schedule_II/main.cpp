#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(int numCourses, vector<vector<int>>& adj) {
	vector<int> inDegree(numCourses, 0);
	for(int u = 0; u < numCourses; u++) {
		for(int v: adj[u]) {
			inDegree[v]++;
		}
	}

	queue<int> q;
	
	for(int i = 0; i < numCourses; i++) {
		if(inDegree[i] == 0) {
			q.push(i);
		}
	}

	vector<int> topoOrder;

	while(!q.empty()) {
		int u = q.front();
		q.pop();
		topoOrder.push_back(u);

		for(int v: adj[u]) {
			if(--inDegree[v] == 0) {
				q.push(v);
			}
		}
	}

	int topoSize = topoOrder.size();
	if(topoSize != numCourses) {
		topoOrder.clear();
	}

	return topoOrder;
}


vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	vector<vector<int>> adj(numCourses);

	for(vector<int> prerequisite: prerequisites) {
		int from = prerequisite[1];
		int to = prerequisite[0];

		adj[from].push_back(to);
	}

	vector<int> result = topologicalSort(numCourses, adj);
	return result;
}

int main(){
	int numCourses = 4;
	vector<vector<int>> prerequisites = {
		{1,0},{2,0},{3,1},{3,2}
	};

	vector<int> result = findOrder(numCourses, prerequisites);
	for(int val: result) {
		cout << val << ' ';
	}

	return 0;
}
