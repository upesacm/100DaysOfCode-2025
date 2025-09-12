public class Day_88_Question_2 {

    // Counts number of islands using DFS
    public static int numIslands(int[][] grid) {
        int count = 0;
        int rows = grid.length, cols = grid[0].length;
        boolean[][] visited = new boolean[rows][cols];
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1 && !visited[r][c]) {
                    dfs(grid, visited, r, c);
                    count++;
                }
            }
        }
        return count;
    }

    private static void dfs(int[][] grid, boolean[][] visited, int r, int c) {
        if (r < 0 || c < 0 || r >= grid.length || c >= grid[0].length) return;
        if (grid[r][c] == 0 || visited[r][c]) return;
        visited[r][c] = true;
        dfs(grid, visited, r + 1, c);
        dfs(grid, visited, r - 1, c);
        dfs(grid, visited, r, c + 1);
        dfs(grid, visited, r, c - 1);
    }

    public static void main(String[] args) {
        int[][] grid1 = {{1,1,0,0},{1,0,0,1},{0,0,1,1}};
        System.out.println(numIslands(grid1)); // Output: 3

        int[][] grid2 = {{1,1,0},{0,1,0},{0,0,1}};
        System.out.println(numIslands(grid2)); // Output: 2
    }
}
