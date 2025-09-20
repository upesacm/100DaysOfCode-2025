public class Day_96_Question_2 {

    // Subset Sum DP: returns true if subset with target sum exists
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

    // Partition Equal Subset Sum: returns true if array can be partitioned into two equal-sum subsets
    public static boolean canPartition(int[] arr) {
        int total = 0;
        for (int num : arr) total += num;
        if (total % 2 != 0) return false;
        return subsetSum(arr, total / 2);
    }

    public static void main(String[] args) {
        int[] arr1 = {3, 34, 4, 12, 5, 2};
        int target1 = 9;
        System.out.println(subsetSum(arr1, target1) ? "Yes" : "No"); // Output: Yes

        int[] arr2 = {1, 2, 3};
        int target2 = 7;
        System.out.println(subsetSum(arr2, target2) ? "Yes" : "No"); // Output: No

        int[] arr3 = {1, 5, 11, 5};
        System.out.println(canPartition(arr3) ? "Yes" : "No"); // Output: Yes

        int[] arr4 = {1, 2, 3, 5};
        System.out.println(canPartition(arr4) ? "Yes" : "No"); // Output: No
    }
}
