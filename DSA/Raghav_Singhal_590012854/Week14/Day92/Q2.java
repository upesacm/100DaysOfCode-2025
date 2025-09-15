public class Q2 {
    public static int climbStairs(int n) {
        if (n <= 2) return n;
        int[] dp = new int[n+1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    public static void main(String[] args) {
        System.out.println(climbStairs(3)); // Output: 3
        System.out.println(climbStairs(4)); // Output: 5
    }
}
