#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int cost, x, y;
};

bool operator>(const Node& a, const Node& b) {
    return a.cost > b.cost;
}

int dijkstra(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dist(m, vector<int>(n, 1e9));
    dist[0][0] = grid[0][0];

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({grid[0][0], 0, 0});

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 1};

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        int x = cur.x, y = cur.y, cost = cur.cost;

        if (x == m-1 && y == n-1)
            return cost;

        if (cost > dist[x][y])
            continue;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                int newCost = cost + grid[nx][ny];

                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, nx, ny});
                }
            }
        }
    }

    return -1;
}

int main() {
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter the grid values:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = dijkstra(grid);

    cout << "Minimum cost = " << result << endl;

    return 0;
}
