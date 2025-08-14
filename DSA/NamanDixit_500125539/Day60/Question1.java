import java.util.*;

public class Question1 {

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

        // Extract remaining from heap
        while (!minHeap.isEmpty()) {
            result.add(minHeap.poll());
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input array size
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        // Input k
        System.out.print("Enter value of k: ");
        int k = sc.nextInt();

        // Sort and display
        List<Integer> sorted = sortKSortedArray(arr, k);
        System.out.println(sorted);

        sc.close();
    }
}
