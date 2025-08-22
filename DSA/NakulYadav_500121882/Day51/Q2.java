import java.util.*;

public class Q2 {
    public static void main(String[] args) {
        int[] arr = {1, 4, 45, 6, 0, 19};
        int x = 51;
        System.out.println(smallestSubarrayLength(arr, x));
    }

    public static int smallestSubarrayLength(int[] arr, int x) {
        int n = arr.length, minLen = Integer.MAX_VALUE;
        int start = 0, sum = 0;

        for (int end = 0; end < n; end++) {
            sum += arr[end];

            while (sum > x) {
                minLen = Math.min(minLen, end - start + 1);
                sum -= arr[start++];
            }
        }

        return minLen == Integer.MAX_VALUE ? 0 : minLen;
    }
}
