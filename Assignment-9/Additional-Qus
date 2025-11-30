#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for(int nbr : adj[node]) {
        if(!visited[nbr]) {
            dfs(nbr, adj, visited);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(V, false);
    int components = 0;

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            dfs(i, adj, visited);
            components++;
        }
    }

    cout << components;
    return 0;
}
