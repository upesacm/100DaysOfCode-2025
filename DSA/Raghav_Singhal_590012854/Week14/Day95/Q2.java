import java.util.*;

public class Q2 {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int[][] dp = new int[m][n];
        if (obstacleGrid[0][0] == 1) return 0;
        dp[0][0] = 1;
        for (int j = 1; j < n; j++) dp[0][j] = (obstacleGrid[0][j] == 0 && dp[0][j - 1] == 1) ? 1 : 0;
        for (int i = 1; i < m; i++) dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i - 1][0] == 1) ? 1 : 0;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                else dp[i][j] = 0;
            }
        }
        return dp[m - 1][n - 1];
    }

    public static void main(String[] args) {
        Q2 obj = new Q2();
        int[][] grid1 = {{0,0,0}, {0,1,0}, {0,0,0}};
        int[][] grid2 = {{0,1}, {0,0}};
        System.out.println("Unique Paths with Obstacles (3x3): " + obj.uniquePathsWithObstacles(grid1));
        System.out.println("Unique Paths with Obstacles (2x2): " + obj.uniquePathsWithObstacles(grid2));
    }
}
