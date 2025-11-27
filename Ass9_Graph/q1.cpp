#include <iostream>
using namespace std;

int main() {
    int n = 5;

    int adj[10][10] = {0};

    adj[0][1] = 1;
    adj[0][2] = 1;
    adj[1][3] = 1;
    adj[2][4] = 1;

    int visited[10] = {0};
    int queue[10];
    int front = 0, rear = 0;

    int start = 0;

    visited[start] = 1;
    queue[rear++] = start;

    cout << "BFS Traversal: ";

    while (front != rear) {
        int node = queue[front++];
        cout << node << " ";

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    return 0;
}
