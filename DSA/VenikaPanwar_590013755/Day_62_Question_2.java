import java.util.*;

public class KClosestNumbers {
    public static List<Integer> findClosest(int[] arr, int target, int k) {
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((a, b) -> b[0] - a[0]);

        for (int num : arr) {
            int dist = Math.abs(num - target);
            maxHeap.add(new int[]{dist, num});
            if (maxHeap.size() > k) maxHeap.poll();
        }

        List<Integer> result = new ArrayList<>();
        for (int[] pair : maxHeap) result.add(pair[1]);
        Collections.sort(result); // sorted output for readability
        return result;
    }

    public static void main(String[] args) {
        System.out.println(findClosest(new int[]{1, 2, 3, 4, 5}, 3, 2)); // [2, 4]
        System.out.println(findClosest(new int[]{5, 6, 7, 8, 9}, 7, 3)); // [6, 7, 8]
    }
}
