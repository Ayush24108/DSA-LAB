#include <iostream>
using namespace std;

#define INF 999999

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int graph[50][50];

    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
            if (i != j && graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    int dist[50], visited[50];

    // initialize
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int c = 0; c < V - 1; c++) {

        
        int minDist = INF, u = -1;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        visited[u] = 1;


        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

  
    cout << "Dijkstra Shortest Path Result:"<<endl;
    for (int i = 0; i < V; i++) {
        cout << "Distance from " << src << " to " << i << " = " << dist[i] << endl;
    }

    return 0;
}
