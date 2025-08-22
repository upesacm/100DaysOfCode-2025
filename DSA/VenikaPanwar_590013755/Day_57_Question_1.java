import java.util.*;

public class KLargestElements {
    public static List<Integer> kLargest(int[] arr, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        for (int num : arr) {
            minHeap.add(num);
            if (minHeap.size() > k) {
                minHeap.poll(); // remove smallest
            }
        }

        List<Integer> result = new ArrayList<>(minHeap);
        result.sort(Collections.reverseOrder()); // descending order
        return result;
    }

    public static void main(String[] args) {
        System.out.println(kLargest(new int[]{1, 23, 12, 9, 30, 2, 50}, 3)); // [50, 30, 23]
        System.out.println(kLargest(new int[]{10, 15, 5}, 2)); // [15, 10]
    }
}
