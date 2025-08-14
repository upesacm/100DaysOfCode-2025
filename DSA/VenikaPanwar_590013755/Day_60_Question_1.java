import java.util.*;

public class KSortedArray {
    public static List<Integer> sortKSortedArray(int[] arr, int k) {
        List<Integer> result = new ArrayList<>();
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        // Add first k+1 elements to heap
        for (int i = 0; i <= k && i < arr.length; i++) {
            minHeap.add(arr[i]);
        }

        // Process remaining elements
        for (int i = k + 1; i < arr.length; i++) {
            result.add(minHeap.poll());
            minHeap.add(arr[i]);
        }

        // Add remaining elements from heap
        while (!minHeap.isEmpty()) {
            result.add(minHeap.poll());
        }

        return result;
    }

    public static void main(String[] args) {
        System.out.println(sortKSortedArray(new int[]{6, 5, 3, 2, 8, 10, 9}, 3));
        System.out.println(sortKSortedArray(new int[]{3, 2, 1, 5, 4, 7, 6, 5}, 3));
    }
}
