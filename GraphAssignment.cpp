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
    while(! q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<endl;
        for(auto v: adj[u]){
            if(visited[v] == false){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
void printGraph(vector<int>adj[], int vertex){
    for(int i=0; i<vertex; i++){
        for(auto x: adj[i]){
            cout<<x<<" ";
        }
    }
    cout<<endl;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
   
    int vertex = 5;
    vector<int>adj[vertex];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);

    printGraph(adj, vertex);
    BFS(adj, vertex, 0);

    return 0;
}
