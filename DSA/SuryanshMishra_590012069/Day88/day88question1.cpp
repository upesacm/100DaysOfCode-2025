#include <vector>
#include <queue>
#include <cstddef>
#include <functional>
#include <cmath>

using namespace std;

// Flood fill using DFS
void floodFillDFS(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int m = image.size(), n = m ? image[0].size() : 0;
    if (sr < 0 || sr >= m || sc < 0 || sc >= n) return;
    int oldColor = image[sr][sc];
    if (oldColor == newColor) return;
    function<void(int,int)> dfs = [&](int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n) return;
        if (image[r][c] != oldColor) return;
        image[r][c] = newColor;
        dfs(r+1, c); dfs(r-1, c); dfs(r, c+1); dfs(r, c-1);
    };
    dfs(sr, sc);
}

// Flood fill using BFS
void floodFillBFS(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int m = image.size(), n = m ? image[0].size() : 0;
    if (sr < 0 || sr >= m || sc < 0 || sc >= n) return;
    int oldColor = image[sr][sc];
    if (oldColor == newColor) return;
    queue<pair<int,int>> q;
    q.push({sr, sc});
    image[sr][sc] = newColor;
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int r = p.first, c = p.second;
        for (int dr = -1; dr <= 1; ++dr) {
            for (int dc = -1; dc <= 1; ++dc) {
                if (abs(dr) + abs(dc) != 1) continue; // only 4 directions
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && image[nr][nc] == oldColor) {
                    image[nr][nc] = newColor;
                    q.push({nr, nc});
                }
            }
        }
    }
}

// Wrapper: returns filled image using DFS
vector<vector<int>> floodFill(vector<vector<int>> image, int sr, int sc, int newColor) {
    floodFillDFS(image, sr, sc, newColor);
    return image;
}
