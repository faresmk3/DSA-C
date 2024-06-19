#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class BFS_graphs
{

public:
  // Function to return breadth first traversal items of a graph
  // V is the number of nodes, adj is the given adjacency list
  vector<int> BfsTraversal(int V, vector<int> adj[]) {
    vector<int> bfs;
    int visited[V] = {0};
    queue<int> q;
    q.push(0);
    visited[0] = 1;

    while (!q.empty()) {
      int node = q.front();
      q.pop();
      bfs.push_back(node);
      for (auto item : adj[node]) {
        if (! visited[item]) {
          visited[item] = 1;
          q.push(item);
        }
      }
    }
    return bfs;
  }
};

