import java.util.*;

public class Question2 {

    public static long maxSumOfDistinctSubarrays(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        long maxSum = 0, curSum = 0;

        for (int i = 0; i < nums.length; i++) {
            curSum += nums[i];
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);

            if (i >= k - 1) {
                if (mp.size() == k) {
                    maxSum = Math.max(maxSum, curSum);
                }

                curSum -= nums[i - k + 1];
                mp.put(nums[i - k + 1], mp.get(nums[i - k + 1]) - 1);

                if (mp.get(nums[i - k + 1]) == 0) {
                    mp.remove(nums[i - k + 1]);
                }
            }
        }

        return maxSum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();  // size of array
        int[] nums = new int[n];

        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        int k = sc.nextInt();  // length of subarray

        long result = maxSumOfDistinctSubarrays(nums, k);
        System.out.println(result);
    }
}
