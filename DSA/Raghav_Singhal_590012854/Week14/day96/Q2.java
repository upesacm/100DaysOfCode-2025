public class Q2 {
    public static boolean subsetSum(int[] arr, int target) {
        int n = arr.length;
        boolean[][] dp = new boolean[n + 1][target + 1];
        for (int i = 0; i <= n; i++) dp[i][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int sum = 1; sum <= target; sum++) {
                if (arr[i - 1] <= sum) {
                    dp[i][sum] = dp[i - 1][sum] || dp[i - 1][sum - arr[i - 1]];
                } else {
                    dp[i][sum] = dp[i - 1][sum];
                }
            }
        }
        return dp[n][target];
    }

    public static void main(String[] args) {
        int[] arr = {3, 34, 4, 12, 5, 2};
        int target = 9;
        System.out.println(subsetSum(arr, target) ? "Yes" : "No");
    }
}
