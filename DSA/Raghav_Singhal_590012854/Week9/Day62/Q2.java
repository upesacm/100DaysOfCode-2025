import java.util.*;

public class Q2 {
    public static List<Integer> kClosest(int[] arr, int target, int k) {
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>(
            (a, b) -> a[0] == b[0] ? b[1] - a[1] : b[0] - a[0]
        );

        for (int num : arr) {
            int distance = Math.abs(num - target);
            maxHeap.add(new int[]{distance, num});
            if (maxHeap.size() > k) {
                maxHeap.poll();
            }
        }

        List<Integer> result = new ArrayList<>();
        while (!maxHeap.isEmpty()) {
            result.add(maxHeap.poll()[1]);
        }
        Collections.sort(result);
        return result;
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 2, 3, 4, 5};
        int target1 = 3, k1 = 2;
        System.out.println("K Closest: " + kClosest(arr1, target1, k1));

        int[] arr2 = {10, 15, 7, 3, 4};
        int target2 = 8, k2 = 3;
        System.out.println("K Closest: " + kClosest(arr2, target2, k2));
    }
}
