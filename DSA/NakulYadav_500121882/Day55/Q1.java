import java.util.*;

public class Q1 {
    public static int longestSubarraySumK(int[] arr, int k) {
        Map<Integer, Integer> prefixMap = new HashMap<>();
        int sum = 0, maxLen = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
            if (sum == k) maxLen = i + 1;
            if (!prefixMap.containsKey(sum)) prefixMap.put(sum, i);
            if (prefixMap.containsKey(sum - k)) {
                maxLen = Math.max(maxLen, i - prefixMap.get(sum - k));
            }
        }
        return maxLen;
    }

    public static void main(String[] args) {
        int[] arr = {10, 5, 2, 7, 1, 9};
        System.out.println(longestSubarraySumK(arr, 15));
    }
}
