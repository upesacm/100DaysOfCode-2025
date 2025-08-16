import java.util.*;

public class Question3 {

    // Function to find kth largest subarray sum
    public static int kthLargestSubarraySum(int[] arr, int k) {
        int n = arr.length;

        // Step 1: Compute prefix sums
        int[] prefix = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        // Step 2: Min-heap to store top k sums
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        // Step 3: Generate all subarray sums
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = prefix[j + 1] - prefix[i];

                if (minHeap.size() < k) {
                    minHeap.offer(sum);
                } else if (sum > minHeap.peek()) {
                    minHeap.poll();
                    minHeap.offer(sum);
                }
            }
        }

        // Step 4: Return kth largest
        return minHeap.peek();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.print("Enter k: ");
        int k = sc.nextInt();

        // Output
        int result = kthLargestSubarraySum(arr, k);
        System.out.println(result);

        sc.close();
    }
}
