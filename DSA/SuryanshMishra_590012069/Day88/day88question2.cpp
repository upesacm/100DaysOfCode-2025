#include <vector>
#include <cstddef>
#include <functional>

using namespace std;

// Count number of islands (connected components of 1s) in a binary grid using DFS.
int numIslands(vector<vector<int>>& grid) {
    int m = grid.size(), n = m ? grid[0].size() : 0;
    int count = 0;
    function<void(int,int)> dfs = [&](int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 1) return;
        grid[r][c] = -1; // mark visited
        dfs(r+1, c); dfs(r-1, c); dfs(r, c+1); dfs(r, c-1);
    };
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                ++count;
                dfs(i, j);
            }
        }
    }
    return count;
}
