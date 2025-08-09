public class SubarraysProductLessThanK {
    public static int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1) return 0; // no valid subarray possible

        int count = 0, left = 0;
        long product = 1;

        for (int right = 0; right < nums.length; right++) {
            product *= nums[right];

            while (product >= k) {
                product /= nums[left++];
            }

            // number of subarrays ending at right = window length
            count += (right - left + 1);
        }

        return count;
    }

    public static void main(String[] args) {
        System.out.println(numSubarrayProductLessThanK(new int[]{10, 5, 2, 6}, 100)); // 8
        System.out.println(numSubarrayProductLessThanK(new int[]{1, 2, 3}, 0));       // 0
    }
}
