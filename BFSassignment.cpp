#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void BFS(vector<int>adj[], int vertex, int source){
    vector<bool>visited(vertex, false);
    queue<int>q;
    visited[source] = true;
    q.push(source);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<endl;
        for(auto v: adj[u]){
            if(visited[v] == false){
                visited[v] == true;
                q.push(v);
            }
        }
    }
}
// void printGraph(vector<int>adj[], int v){
//     for(int i=0; i<v; i++){
//         for(auto x: adj[i]) cout<<x<<" ";
//     }
// }
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    // Create a graph with 5 vertices
    int v=5;
    vector<int>adj[v];

    // Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);

    // Perform BFS starting from vertex 0
    BFS(adj, v, 0);

    // printGraph(adj, v);

    return 0;
}
