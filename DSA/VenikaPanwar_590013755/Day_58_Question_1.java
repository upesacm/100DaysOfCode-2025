import java.util.*;

public class KthSmallestElement {
    public static int kthSmallest(int[] arr, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int num : arr) {
            minHeap.add(num);
        }

        // Extract k-1 smallest elements
        for (int i = 0; i < k - 1; i++) {
            minHeap.poll();
        }

        return minHeap.peek(); // kth smallest
    }

    public static void main(String[] args) {
        System.out.println(kthSmallest(new int[]{7, 10, 4, 3, 20, 15}, 3)); // 7
        System.out.println(kthSmallest(new int[]{7, 10, 4, 20, 15}, 4));    // 15
    }
}

