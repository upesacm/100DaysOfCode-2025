import java.util.*;

public class LongestSubarraySumK {
    public static int longestSubarray(int[] arr, int k) {
        Map<Integer, Integer> prefixMap = new HashMap<>();
        int sum = 0, maxLen = 0;

        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];

            if (sum == k) {
                maxLen = i + 1;
            }

            if (!prefixMap.containsKey(sum)) {
                prefixMap.put(sum, i);
            }

            if (prefixMap.containsKey(sum - k)) {
                maxLen = Math.max(maxLen, i - prefixMap.get(sum - k));
            }
        }

        return maxLen;
    }

    public static void main(String[] args) {
        System.out.println(longestSubarray(new int[]{10, 5, 2, 7, 1, 9}, 15)); // 4
        System.out.println(longestSubarray(new int[]{1, 2, 3}, 3));           // 2
    }
}
