import java.util.*;

public class Q1 {
    public static void main(String[] args) {
        int[] arr = {1, 4, 2, 10};
        int k = 2;
        System.out.println(maxSum(arr, k));
    }

    public static int maxSum(int[] arr, int k) {
        int maxSum = 0, windowSum = 0;
        for (int i = 0; i < k; i++) windowSum += arr[i];
        maxSum = windowSum;

        for (int i = k; i < arr.length; i++) {
            windowSum += arr[i] - arr[i - k];
            maxSum = Math.max(maxSum, windowSum);
        }

        return maxSum;
    }
}
