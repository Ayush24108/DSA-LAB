#include <iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    vector<vector<int>> dist(m, vector<int>(n, 1000));
    dist[0][0] = grid[0][0];

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({grid[0][0], 0, 0});  

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int cost = top[0];
        int r = top[1];
        int c = top[2];

        if (r == m-1 && c == n-1) {
            cout << cost;
            return 0;
        }

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                int newCost = cost + grid[nr][nc];
                if (newCost < dist[nr][nc]) {
                    dist[nr][nc] = newCost;
                    pq.push({newCost, nr, nc});
                }
            }
        }
    }

    cout << dist[m-1][n-1];
    return 0;
}
