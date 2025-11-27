#include <iostream>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    int graph[100][100];  

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = INF;

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u][v] = w;
        graph[v][u] = w;  
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    int dist[100];
    bool visited[100];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[source] = 0;

    for (int i = 0; i < n; i++) {

        int minDist = INF, u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break; 

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INF) {  
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    cout << "\nShortest distances from node " << source << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Node " << i << " : " << dist[i] << endl;
    }

    return 0;
}
