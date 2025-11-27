#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    const int INF = 1e9;
    vector<vector<pair<int,int>>> adj(N + 1);

    for (auto &t : times) {
        int u = t[0], v = t[1], w = t[2];
        adj[u].push_back({v, w});
    }

    vector<int> dist(N + 1, INF);
    dist[K] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, K});

    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int d = p.first, u = p.second;

        if (d > dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INF) return -1; 
        ans = max(ans, dist[i]);
    }

    return ans;
}

int main() {
    int N, E, K;
    cout << "Enter number of nodes and edges: ";
    cin >> N >> E;

    vector<vector<int>> times(E, vector<int>(3));

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        cin >> times[i][0] >> times[i][1] >> times[i][2];
    }

    cout << "Enter starting node K: ";
    cin >> K;

    int result = networkDelayTime(times, N, K);
    cout << "Time for all nodes to receive signal: " << result << endl;

    return 0;
}
