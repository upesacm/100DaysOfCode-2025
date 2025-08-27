import java.util.*;

public class Question2 {

    // Function to check if subset sum exists with target k
    public static boolean subsetSumToK(int n, int k, int[] arr) {
        boolean[] prev = new boolean[k + 1];
        boolean[] cur = new boolean[k + 1];

        prev[0] = cur[0] = true;

        if (arr[0] <= k) prev[arr[0]] = true;

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                boolean notTake = prev[target];
                boolean take = false;
                if (arr[ind] <= target) take = prev[target - arr[ind]];
                cur[target] = take || notTake;
            }
            prev = cur.clone();
        }
        return prev[k];
    }

    // Function to check partition feasibility
    public static boolean canPartition(int[] arr, int n) {
        int totSum = 0;
        for (int i = 0; i < n; i++) totSum += arr[i];

        if (totSum % 2 != 0) return false; // Odd sum can't be partitioned equally

        int k = totSum / 2;
        return subsetSumToK(n, k, arr);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input size
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // Output true or false
        System.out.println(canPartition(arr, n));
    }
}
