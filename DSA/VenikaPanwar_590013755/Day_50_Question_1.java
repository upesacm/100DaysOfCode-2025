import java.util.Scanner;

public class MaxSumSubarrayK {
    public static int maxSum(int[] arr, int k) {
        int n = arr.length;
        if (n < k) return -1;

        int windowSum = 0;
        for (int i = 0; i < k; i++) windowSum += arr[i];

        int maxSum = windowSum;

        for (int i = k; i < n; i++) {
            windowSum += arr[i] - arr[i - k];
            maxSum = Math.max(maxSum, windowSum);
        }

        return maxSum;
    }

    public static void main(String[] args) {
        int[] arr = {1, 4, 2, 10};
        int k = 2;
        System.out.println("Maximum sum subarray of size " + k + " is: " + maxSum(arr, k));
    }
}
