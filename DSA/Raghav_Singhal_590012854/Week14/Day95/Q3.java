import java.util.*;

public class Q3 {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] dp = new int[m][n];
        dp[0][0] = grid[0][0];
        for (int j = 1; j < n; j++) dp[0][j] = dp[0][j - 1] + grid[0][j];
        for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] + Math.min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m - 1][n - 1];
    }

    public static void main(String[] args) {
        Q3 obj = new Q3();
        int[][] grid1 = {{1,3,1}, {1,5,1}, {4,2,1}};
        int[][] grid2 = {{1,2,3}, {4,5,6}};
        System.out.println("Minimum Path Sum (3x3): " + obj.minPathSum(grid1));
        System.out.println("Minimum Path Sum (2x3): " + obj.minPathSum(grid2));
    }
}
