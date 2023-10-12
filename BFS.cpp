// 212010191
// Sakhawat Hossain
#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V; 
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void BFS(int startVertex) {
        vector<bool> visited(V, false);

        // Create a queue for BFS
        queue<int> bfsQueue;

       visited[startVertex] = true;
        bfsQueue.push(startVertex);

        cout << "Breadth-First: " << startVertex << ": ";

        while (!bfsQueue.empty()) {
            int currentVertex = bfsQueue.front();
            cout << currentVertex << " ";
            bfsQueue.pop();

            for (const int& neighbor : adj[currentVertex]) {
                if (!visited[neighbor]) {
                    // Mark the adjacent vertex as visited and enqueue it
                    visited[neighbor] = true;
                    bfsQueue.push(neighbor);
                }
            }
        }

        cout << endl;
    }
};

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    // Create a graph with 6 vertices
    Graph graph(6);
    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    // Perform BFS starting from vertex 0
    graph.BFS(0);

    return 0;
}
