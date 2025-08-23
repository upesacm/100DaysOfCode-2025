import java.util.*;

public class Day_69_Question_2 {
    /**
     * Checks if array can be split into two subsets with equal sum.
     * Uses subset sum DP for feasibility.
     */
    public static boolean canSplitEqualSum(int[] arr) {
        int total = Arrays.stream(arr).sum();
        if (total % 2 != 0) return false;
        int target = total / 2;
        boolean[] dp = new boolean[target + 1];
        dp[0] = true;
        for (int num : arr) {
            for (int i = target; i >= num; i--) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        return dp[target];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter array size: ");
        int n = scanner.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) arr[i] = scanner.nextInt();
        boolean result = canSplitEqualSum(arr);
        System.out.println(result);

        // Example demonstrations
        System.out.println("Example: [1, 2, 3, 5] -> " + canSplitEqualSum(new int[]{1,2,3,5}));
        System.out.println("Example: [1, 5, 11, 5] -> " + canSplitEqualSum(new int[]{1,5,11,5}));
        scanner.close();
    }
}
