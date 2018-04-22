#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#define INF 10000000
using namespace std;

// write your matric number here: A0170761H
// write your name here: James Arista Yaputra
// write list of collaborators here: Ler Wei Sheng, Arjo
// year 2017 Sem2 hash code: WxxVfOfqw6Be7Cyq2acb (do NOT delete this line)

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

int V; // number of vertices in the graph (number of junctions in Singapore map)
int Q; // number of queries
vector<vector<ii>> adjList; //adjacency list for BF's to refer to

int BF(int source, int destination, int k) {
  int ans;
  vector<vector<int> > dist;

  //Assigns values
  dist.assign(V, vector<int> (V, INF));
  dist[0][source] = 0;
  
  for (int i = 1; i < k; i++) {
    for (int j = 0; j < V; j++) {
      int v = j;
      for (auto &it : adjList[j]) {
        int v1 = it.first;
        int weight = it.second;

        if (dist[i][v1] > dist[i-1][v] + weight) dist[i][v1] = dist[i-1][v] + weight;
      }
    }

    for (int j = 0; j < V; j++) if (dist[i][j] > dist[i-1][j]) dist[i][j] = dist[i-1][j];
  }

  if (dist[k-1][destination] == INF) ans = -1;
  else ans = dist[k-1][destination];
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  int TC;
  scanf("%d", &TC);

  while (TC--) {
    int j, k, w;
    scanf("%d", &V);

    // clear the graph and read in a new graph as Adjacency List
    adjList.assign(V, vector<ii>());

    for (int i = 0; i < V; i++) {
      scanf("%d", &k);
      while (k--) {
        scanf("%d %d", &j, &w);
        adjList[i].emplace_back(j, w); // edge (road) weight (in minutes) is stored here
      }
    }

    int source, destination, required_k;
    
    scanf("%d", &Q);
    while (Q--) {
      scanf("%d %d %d", &source, &destination, &required_k);
      printf("%d\n", BF(source, destination, required_k));
    }

    if (TC)
      printf("\n");
  }
  return 0;
}