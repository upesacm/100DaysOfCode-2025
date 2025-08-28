import java.util.*;

public class Q3 {
    public static int largestSumAfterKNegations(int[] nums, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int num : nums) minHeap.offer(num);

        while (k-- > 0) {
            int smallest = minHeap.poll();
            minHeap.offer(-smallest);
        }

        int sum = 0;
        for (int num : minHeap) sum += num;
        return sum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) nums[i] = sc.nextInt();
        System.out.println(largestSumAfterKNegations(nums, k));
        sc.close();
    }
}
