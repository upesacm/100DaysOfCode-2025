#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& grid, int x, int y) {
    int m = grid.size(), n = grid[0].size();
    if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0) return;

    grid[x][y] = 0; 

    dfs(grid, x+1, y);
    dfs(grid, x-1, y);
    dfs(grid, x, y+1);
    dfs(grid, x, y-1);
}

int numIslands(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                dfs(grid, i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<vector<int>> grid = {{1,1,0,0},{1,0,0,1},{0,0,1,1}};
    cout << "Number of Islands: " << numIslands(grid) << endl;
    return 0;
}
