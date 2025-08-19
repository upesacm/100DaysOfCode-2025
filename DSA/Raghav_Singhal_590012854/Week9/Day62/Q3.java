import java.util.*;

public class Q3 {
    public static int kthLargestSum(int[] arr, int k) {
        int n = arr.length;

        int[] prefix = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int sum = prefix[j] - prefix[i]; 

                minHeap.offer(sum);

                if (minHeap.size() > k) {
                    minHeap.poll();
                }
            }
        }

        return minHeap.peek();
    }

    public static void main(String[] args) {
        int[] arr1 = {10, -10, 20, -40};
        int k1 = 3;
        System.out.println(kthLargestSum(arr1, k1)); 

        int[] arr2 = {1, 2, 3};
        int k2 = 2;
        System.out.println(kthLargestSum(arr2, k2)); 
    }
}
