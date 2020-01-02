#include<bits/stdc++.h>
using namespace std;

class Graph{
  int V;
  list<int> *adj;
  //Why this * is important

public:
  Graph(int V);
  void addEdge(int u, int v);
  void BFS(int s);
};

Graph::Graph(int V)
{
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
  adj[u].push_back(v);
}
void Graph::BFS(int s)
{
  //record for all the visited vertices, initailly none are visited
  bool* visited = new bool[V];
  for(int i = 0; i < V; i++)
        visited[i] = false;
  //queue for BFS
  list<int> queue;

  //mark the starting vertex as visited
  visited[s] = true;
  queue.push_back(s);

  while(!queue.empty())
  {
    s = queue.front();
    cout << s << " ";
    queue.pop_front();
    for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
  }
}
  // Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}
