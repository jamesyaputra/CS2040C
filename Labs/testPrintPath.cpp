#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
vector<vi> adj;
vi visited;
vi output;
bool found = false;

void dfs(int source, int dest) {
	visited[source] = 1;
	if (source == dest) found = true;
	for (auto &it : adj[source]) {
		if (found) break;
		if (!visited[it]) dfs(it, dest);
	}
	if (found) output.push_back(source);
}

int main () {
	int v, e;

	cin >> v >> e;
	adj.assign(v, vi());
	visited.assign(v, 0);
	while (e--) {
		int a, b;
		cin >> a >> b;
		adj[a-1].push_back(b-1);
	}

	int i, j;
	cin >> i >> j;
	dfs(i-1, j-1);

	for (int i = output.size()-1; i >= 0; i--)
		cout << output[i]+1 << " ";
	cout << endl;
}