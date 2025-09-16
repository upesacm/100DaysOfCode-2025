public class Q2 {
    public static int maxSubArray(int[] nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.length; i++) {
            currentSum = Math.max(nums[i], currentSum + nums[i]);
            maxSum = Math.max(maxSum, currentSum);
        }

        return maxSum;
    }

    public static void main(String[] args) {
        int[] arr1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        System.out.println(maxSubArray(arr1)); // 6

        int[] arr2 = {1};
        System.out.println(maxSubArray(arr2)); // 1

        int[] arr3 = {5, 4, -1, 7, 8};
        System.out.println(maxSubArray(arr3)); // 23

        int[] arr4 = {-1, -2, -3, -4};
        System.out.println(maxSubArray(arr4)); // -1 (best single element)
    }
}
