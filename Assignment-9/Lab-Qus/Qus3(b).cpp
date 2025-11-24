#include <iostream>
using namespace std;

#define INF 999999

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int graph[50][50];

    cout << "Enter adjacency matrix (use 0 if no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0)
                graph[i][j] = INF;  
        }
        graph[i][i] = 0;  
    }

    int visited[50] = {0};
    int key[50];
    int parent[50];

  
    for (int i = 0; i < V; i++)
        key[i] = INF;

    key[0] = 0;      
    parent[0] = -1;    

   
    for (int c = 0; c < V - 1; c++) {

        
        int minKey = INF, u = -1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        visited[u] = 1;

       
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != INF && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Prim's MST Result:"<<endl;
    int totalCost = 0;

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " : " << graph[parent[i]][i] << endl;
        totalCost += graph[parent[i]][i];
    }

    cout << "Total Cost = " << totalCost << endl;

    return 0;
}
