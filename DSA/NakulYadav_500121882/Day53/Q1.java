public class Q1 {
    public static void main(String[] args) {
        int[] nums = {1, 1, 0, 1, 1, 1};
        System.out.println(findMaxConsecutiveOnes(nums));
    }

    public static int findMaxConsecutiveOnes(int[] nums) {
        int max = 0, count = 0;
        for (int num : nums) {
            count = (num == 1) ? count + 1 : 0;
            max = Math.max(max, count);
        }
        return max;
    }
}
