import java.util.*;

public class BinarySubarraySum {
    public static int numSubarraysWithSum(int[] nums, int goal) {
        Map<Integer, Integer> freqMap = new HashMap<>();
        freqMap.put(0, 1); // base case: sum=0 has 1 occurrence

        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;
            if (freqMap.containsKey(sum - goal)) {
                count += freqMap.get(sum - goal);
            }
            freqMap.put(sum, freqMap.getOrDefault(sum, 0) + 1);
        }

        return count;
    }

    public static void main(String[] args) {
        System.out.println(numSubarraysWithSum(new int[]{1, 0, 1, 0, 1}, 2)); // 4
        System.out.println(numSubarraysWithSum(new int[]{0, 0, 0, 0, 0}, 0)); // 15
    }
}
