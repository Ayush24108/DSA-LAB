#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<vector<pair<int,int>>> adj(N + 1);

 
    for (int i = 0; i < times.size(); i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        adj[u].push_back({v, w});
    }


    vector<int> dist(N + 1, 1000000);
    dist[K] = 0;

   
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, K));  

    while (!pq.empty()) {
        pair<int,int> top = pq.top();
        pq.pop();

        int cost = top.first;
        int node = top.second;

        for (int i = 0; i < adj[node].size(); i++) {
            int nbr = adj[node][i].first;
            int w   = adj[node][i].second;

            int new_cost = cost + w;
            if (new_cost < dist[nbr]) {
                dist[nbr] = new_cost;
                pq.push(make_pair(new_cost, nbr));
            }
        }
    }

   
    int max_time = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == 1000000) 
            return -1;   
        max_time = max(max_time, dist[i]);
    }

    return max_time;
}

int main() {
    int N = 4, K = 2;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};

    cout << networkDelayTime(times, N, K);
}
