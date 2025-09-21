class Q3 {
    public int matrixChainOrder(int[] p) {
        int n = p.length - 1; // number of matrices
        int[][] dp = new int[n + 1][n + 1];

        for (int len = 2; len <= n; len++) {
            for (int i = 1; i <= n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = Integer.MAX_VALUE;
                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                    dp[i][j] = Math.min(dp[i][j], cost);
                }
            }
        }
        return dp[1][n];
    }

    public static void main(String[] args) {
        Q3 obj = new Q3();
        System.out.println(obj.matrixChainOrder(new int[]{1, 2, 3, 4}));   // Output: 18
        System.out.println(obj.matrixChainOrder(new int[]{10, 20, 30}));  // Output: 6000
    }
}
