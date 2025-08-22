import java.util.*;

public class Q1 {
    public static int longestSubarray(int[] arr, int k) {
        Map<Integer, Integer> prefixMap = new HashMap<>();
        int sum = 0, maxLength = 0;

        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
            if (sum == k) {
                maxLength = i + 1;
            }
            if (prefixMap.containsKey(sum - k)) {
                maxLength = Math.max(maxLength, i - prefixMap.get(sum - k));
            }
            if (!prefixMap.containsKey(sum)) {
                prefixMap.put(sum, i);
            }
        }
        return maxLength;
    }

    public static void main(String[] args) {
        int[] arr = {10, 5, 2, 7, 1, 9};
        int k = 15;
        System.out.println(longestSubarray(arr, k)); 
    }
}
