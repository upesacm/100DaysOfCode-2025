public class Day_97_Question_3 {

    // Matrix Chain Multiplication using DP
    // dims: array of matrix dimensions, length = n+1 for n matrices
    public static int matrixChainOrder(int[] dims) {
        int n = dims.length - 1;
        int[][] dp = new int[n][n];
        // dp[i][j] = min cost to multiply matrices i...j
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = Integer.MAX_VALUE;
                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                    dp[i][j] = Math.min(dp[i][j], cost);
                }
            }
        }
        return n == 0 ? 0 : dp[0][n - 1];
    }

    public static void main(String[] args) {
        int[] dims1 = {1, 2, 3, 4};
        System.out.println(matrixChainOrder(dims1)); // Output: 18

        int[] dims2 = {10, 20, 30};
        System.out.println(matrixChainOrder(dims2)); // Output: 6000

        int[] dims3 = {40, 20, 30, 10, 30};
        System.out.println(matrixChainOrder(dims3)); // Output: 26000
    }
}
