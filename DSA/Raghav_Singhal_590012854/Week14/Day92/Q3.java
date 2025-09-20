public class Q3 {
    public static int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        if (n == 1) return cost[0];
        int[] dp = new int[n];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + Math.min(dp[i-1], dp[i-2]);
        }
        return Math.min(dp[n-1], dp[n-2]);
    }

    public static void main(String[] args) {
        int[] cost1 = {10, 15, 20};
        int[] cost2 = {1,100,1,1,1,100,1,1,100,1};

        System.out.println(minCostClimbingStairs(cost1)); // Output: 15
        System.out.println(minCostClimbingStairs(cost2)); // Output: 6
    }
}
