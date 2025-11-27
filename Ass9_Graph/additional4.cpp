#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
    int m = grid.size();
    int n = grid[0].size();

    if (x < 0 || x >= m || y < 0 || y >= n)
        return;

    if (grid[x][y] == 0 || visited[x][y])
        return;

    visited[x][y] = true;

    // explore 4 directions
    dfs(x + 1, y, grid, visited); // down
    dfs(x - 1, y, grid, visited); // up
    dfs(x, y + 1, grid, visited); // right
    dfs(x, y - 1, grid, visited); // left
}

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter grid values (0 or 1):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(m, vector<bool>(n, false));

    int islands = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                islands++;
                dfs(i, j, grid, visited);
            }
        }
    }

    cout << "Number of islands: " << islands << endl;

    return 0;
}
