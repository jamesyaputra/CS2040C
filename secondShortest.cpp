#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <limits.h>
using namespace std;

//Number of vertices
#define V 9
#define INF 10000000

vector<vector<int> > paths;	//to store shortest path
vector<int> dist, parent;	//to store distance and parents of the nodes in the shortest path tree
vector<bool> shortestPath;	//to store nodes in the shortes path tree

//store shortest path from 0 to i
void storePath (int i, int j) {
	if (parent[j] == -1) {
		paths[i].push_back(0);
		return;
 	}
 	storePath(i, parent[j]);
 	paths[i].push_back(j);
}

//store shortest paths from 0 to all V-1 nodes
void storeSolution(int n) {
	int source = 0;
	for (int i = 1; i < V; i++) {
		storePath(i, i);
	}
}

//find shortest unprocessed edge
int minDist() {
	int min = INF, min_index;
	for (int v = 0; v < V; v++) {
		if (shortestPath[v] == false && dist[v] <= min) {
			min = dist[v], min_index = v;
		}
	}
	return min_index;
}

void dijkstra (int graph[V][V], int source) {
	//initialization
	parent[0] = -1; dist[0] = 0;

	for (int i = 0; i < V-1; i++) {
		//minDist routine mimics a priority queue in the
		//standard Dijkstra's implementation
		int u = minDist();
		shortestPath[u] = true;

		//update dist[v] only if it is not in
		//shortestPath, there is an edge from u to v and total
		//weight of path from source to v through u is smaller than current value of
		//dist[v]
		for (int v = 0; v < V; v++) {
			if (!shortestPath[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}

	storeSolution(V);
}

//All functions and globals below are for the second sp routine
vector<vector<int> > storeSecondPath;
vector<int> storeWeight;
int counts = 0;

int minDistance(int distance[], bool sptSet[]) {
    int min = INF, min_index;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && distance[v] <= min) {
            min = distance[v], min_index = v;
    	}
    }
 
    return min_index;
}

void storePath2 (int parents[], int i) {
	if (parents[i] == -1) {
		storeSecondPath[counts].push_back(0);
		return;
	}
 	storePath2(parents, parents[i]);
 	storeSecondPath[counts].push_back(i);
}

void dijkstra_2(int graph[][V], int source, int dest) {
    int distance[V]; 
    bool sptSet[V];
    int parents[V];

    for (int i = 0; i < V; i++) {  
        distance[i] = INT_MAX;
        sptSet[i] = false;
    }
 
    distance[source] = 0;
    parents[0] = -1;
 
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(distance, sptSet);
        sptSet[u] = true;
 
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < distance[v]) {
                parents[v] = u;
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    storeWeight.push_back(distance[dest]);
    storeSecondPath.push_back(vector<int>());
    storePath2(parents, dest);
    counts++;
}

void printSecondShortest(int weight, int index, int dest) {
	cout << dest << endl;
	cout << "Weight of second shortest path to " << dest << ": " << weight << endl;
	cout << "Path of second shortest path to " << dest << ":";
	for (int i = 0; i < storeSecondPath[index].size(); i++) {
		cout << " " << storeSecondPath[index][i];
	}
	cout << endl << endl;

	cout << "Weight of shortest path to " << dest << ": " << dist[dest] << endl;
	cout << "Path of shortest path to " << dest << ":";
	for (int i = 0; i < paths[dest].size(); i++) {
		cout << " " << paths[dest][i];
	}
	cout << endl << endl;
}

void secondShortest(int graph[][V], int source, int dest) {
	for (int i = 1; i < paths[dest].size(); i++) {
		//deletes edge (u,v) in shortest path to dest
		int node = paths[dest][i];
		int temp = graph[parent[node]][node];
		graph[parent[node]][node] = graph[node][parent[node]] = 0;

		dijkstra_2(graph, source, dest);

		//places edge(u, v) back
		graph[parent[node]][node] = graph[node][parent[node]] = temp;
	}

	int min = INF, index = -1;
	for (int i = 0; i < storeWeight.size(); i++) {
		if (storeWeight[i] < min) {
			min = storeWeight[i];
			index = i;
		}
	}

	printSecondShortest(min, index, dest);
}

int main() {
	dist.assign(V, INF);
	parent.assign(V, INF);
	shortestPath.assign(V, false);
	paths.assign(V, vector<int>());
	
	//driver function with adjacency matrix
    int graph[V][V] = { {0, 4, 0, 0, 0, 0, 0, 8, 0  },
                        {4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        {0, 8, 0, 7, 0, 4, 0, 0, 2  },
                        {0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        {0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        {0, 0, 4, 0, 10, 0, 2, 0, 0 },
                        {0, 0, 0, 14, 0, 2, 0, 1, 6 },
                        {8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        {0, 0, 2, 0, 0, 0, 6, 7, 0  }
                    };
 
    dijkstra(graph, 0);
    
    secondShortest(graph, 0, 8);

    return 0;
}