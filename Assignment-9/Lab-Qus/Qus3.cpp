include <iostream>
using namespace std;

class Edge {
public:
    int src, dest, wt;
};

int findParent(int parent[], int v) {
    if (parent[v] == v)
        return v;
    return findParent(parent, parent[v]);
}


void unionSet(int parent[], int rank[], int u, int v) {
    int pu = findParent(parent, u);
    int pv = findParent(parent, v);

    if (rank[pu] < rank[pv])
        parent[pu] = pv;
    else if (rank[pv] < rank[pu])
        parent[pv] = pu;
    else {
        parent[pv] = pu;
        rank[pu]++;
    }
}


void sortEdges(Edge edges[], int E) {
    for (int i = 0; i < E - 1; i++) {
        int minIndex = i;
        for (int j = i+1; j < E; j++) {
            if (edges[j].wt < edges[minIndex].wt)
                minIndex = j;
        }
        // swap
        Edge temp = edges[i];
        edges[i] = edges[minIndex];
        edges[minIndex] = temp;
    }
}

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    Edge edges[100];  

    cout << "Enter edges (src dest weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].wt;
    }

    sortEdges(edges, E);

    int parent[100], rank[100];

  
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    Edge resultMST[100];
    int eCount = 0; 


    for (int i = 0; i < E; i++) {
        if (eCount == V - 1)
            break;

        int u = edges[i].src;
        int v = edges[i].dest;

        int pu = findParent(parent, u);
        int pv = findParent(parent, v);

        if (pu != pv) {  
            resultMST[eCount++] = edges[i];
            unionSet(parent, rank, pu, pv);
        }
    }

    cout << "Kruskal MST Result:"<<endl;
    int totalCost = 0;

    for (int i = 0; i < eCount; i++) {
        cout << resultMST[i].src << " - " 
             << resultMST[i].dest 
             << " : " << resultMST[i].wt << endl;

        totalCost += resultMST[i].wt;
    }

    cout << "Total Cost = " << totalCost << endl;

    return 0;
}
