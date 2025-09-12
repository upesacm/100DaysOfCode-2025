#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& image, int x, int y, int newColor, int oldColor) {
    int m = image.size(), n = image[0].size();
    if (x < 0 || y < 0 || x >= m || y >= n) return;
    if (image[x][y] != oldColor) return;

    image[x][y] = newColor;

    dfs(image, x+1, y, newColor, oldColor);
    dfs(image, x-1, y, newColor, oldColor);
    dfs(image, x, y+1, newColor, oldColor);
    dfs(image, x, y-1, newColor, oldColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    if (oldColor != newColor) dfs(image, sr, sc, newColor, oldColor);
    return image;
}

int main() {
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> result = floodFill(image, sr, sc, newColor);

    cout << "Flood Fill Result:\n";
    for (auto& row : result) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    return 0;
}
