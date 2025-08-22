import java.util.*;

public class KthLargestSubarraySum {
    public static int kthLargestSum(int[] arr, int k) {
        int n = arr.length;
        int[] prefix = new int[n + 1];
        
        for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + arr[i - 1];

        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int start = 0; start < n; start++) {
            for (int end = start; end < n; end++) {
                int sum = prefix[end + 1] - prefix[start];
                minHeap.add(sum);
                if (minHeap.size() > k) minHeap.poll();
            }
        }
        return minHeap.peek();
    }

    public static void main(String[] args) {
        System.out.println(kthLargestSum(new int[]{10, -10, 20, -40}, 3)); // 10
        System.out.println(kthLargestSum(new int[]{1, 2, 3}, 2));          // 5
    }
}
