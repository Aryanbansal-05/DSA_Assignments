#include <iostream>
using namespace std;

int adj[10][10];   
int visited[10];   

void dfs(int node, int n) {
    visited[node] = 1;
    cout << node << " ";

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && visited[i] == 0) {
            dfs(i, n);   
        }
    }
}

int main() {
    int n = 5;  

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            adj[i][j] = 0;

    adj[0][1] = 1;
    adj[0][2] = 1;
    adj[1][3] = 1;
    adj[2][4] = 1;

    for (int i = 0; i < 10; i++)
        visited[i] = 0;

    cout << "DFS Traversal: ";
    dfs(0, n);

    return 0;
}
