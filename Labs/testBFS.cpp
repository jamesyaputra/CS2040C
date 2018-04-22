#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> vi;
vector<vi> adj;
vi visited;
queue<int> q;

void bfs(int source) {
	visited[source] = 1;
	q.push(source);
	while(!q.empty()) {
		int temp = q.front();
		q.pop();

		for (auto &it : adj[temp]) {
			if (!visited[temp]) {
				visited[it] = 1;
				q.push(it);
			}
		}
	}

	return;
}

int main () {
	int v, e;

	cin >> v >> e;
	adj.assign(v, vi());
	while (e--) {
		int a, b;
		cin >> a >> b;
		adj[a-1].push_back(b-1);
	}

	for (auto &it : visited) {
		if (!it) bfs(it);
	}
	return 0;
}