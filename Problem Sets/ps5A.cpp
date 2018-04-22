#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#define INF 2147483647
using namespace std;

// write your matric number here: A0170761H
// write your name here: James Arista Yaputra
// write list of collaborators here: 
// year 2017 Sem2 hash code: WxxVfOfqw6Be7Cyq2acb (do NOT delete this line)

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

int V; // number of vertices in the graph (number of junctions in Singapore map)
int Q; // number of queries
vector<vector<ii>> adjList; //adjacency list for BF to refer to
vector<vector<iii>> store;  //to store shortest paths from all possible source vertices

void dijkstra(int source) {
  priority_queue <ii, vector<ii>, greater<ii> > pq;
  vector<int> dist;
  vector<int> junction;

  //Assigns values
  pq.push(make_pair(0, source));
  dist.assign(V, INF);
  junction.assign(V, INF);
  dist[source] = 0;
  junction[source] = 1;

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    for (auto &it : adjList[u]) {
      int v = it.first;
      int weight = it.second;

      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        junction[v] = junction[u] + 1;
        pq.push(make_pair(dist[v], v));
      }
    }
  }

  for (int i = 0; i < V; i++) {
    store[source].push_back(make_tuple(i, dist[i], junction[i]));
  }
}

int Query(int s, int t, int k) {
  int ans = -1;

  for (int i = 0; i < store[s].size(); i++) {
    if (get<0>(store[s][i]) == t && get<1>(store[s][i]) != INF) ans = get<1>(store[s][i]);
  }

  return ans;
}

int main() {
  int TC;
  scanf("%d", &TC);

  while (TC--) {
    int j, k, w;
    scanf("%d", &V);

    // clear the graph and read in a new graph as Adjacency List
    adjList.assign(V, vector<ii>());
    store.assign(V, vector<iii>());

    for (int i = 0; i < V; i++) {
      scanf("%d", &k);
      while (k--) {
        scanf("%d %d", &j, &w);
        adjList[i].emplace_back(j, w); // edge (road) weight (in minutes) is stored here
      }
    }

    int source, destination, required_k;
    vector<bool> haveDone;
    haveDone.assign(V, false);

    scanf("%d", &Q);
    while (Q--) {
      scanf("%d %d %d", &source, &destination, &required_k);
      if (!haveDone[source]) {
        haveDone[source] = true;
        dijkstra(source);
      }
      printf("%d\n", Query(source, destination, required_k));
    }

    if (TC)
      printf("\n");
  }
  return 0;
}