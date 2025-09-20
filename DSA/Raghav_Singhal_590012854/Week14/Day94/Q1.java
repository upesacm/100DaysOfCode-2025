import java.util.*;

public class Q1 {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;

        int[] dp = new int[n];
        Arrays.fill(dp, 1);

        int maxLength = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            maxLength = Math.max(maxLength, dp[i]);
        }

        return maxLength;
    }

    public static void main(String[] args) {
        Q1 obj = new Q1();

        int[] arr1 = {10, 9, 2, 5, 3, 7, 101, 18};
        System.out.println("LIS length for arr1: " + obj.lengthOfLIS(arr1));

        int[] arr2 = {0, 1, 0, 3, 2, 3};
        System.out.println("LIS length for arr2: " + obj.lengthOfLIS(arr2));
    }
}
