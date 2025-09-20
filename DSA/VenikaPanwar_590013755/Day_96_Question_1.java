public class Day_96_Question_1 {

    // 0/1 Knapsack DP: returns max value for given weights, values, and capacity W
    public static int knapsack(int[] weights, int[] values, int W) {
        int n = weights.length;
        int[][] dp = new int[n + 1][W + 1];
        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (weights[i - 1] <= w) {
                    dp[i][w] = Math.max(
                        dp[i - 1][w], // exclude item
                        values[i - 1] + dp[i - 1][w - weights[i - 1]] // include item
                    );
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }
        return dp[n][W];
    }

    public static void main(String[] args) {
        int[] weights1 = {1, 3, 4, 5};
        int[] values1 = {1, 4, 5, 7};
        int W1 = 7;
        System.out.println(knapsack(weights1, values1, W1)); // Output: 9

        int[] weights2 = {4, 5, 1};
        int[] values2 = {1, 2, 3};
        int W2 = 4;
        System.out.println(knapsack(weights2, values2, W2)); // Output: 3
    }
}