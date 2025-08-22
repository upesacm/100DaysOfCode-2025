public class MaxConsecutiveOnes {
    public static int findMaxConsecutiveOnes(int[] nums) {
        int maxStreak = 0, currentStreak = 0;

        for (int num : nums) {
            if (num == 1) {
                currentStreak++;
                maxStreak = Math.max(maxStreak, currentStreak);
            } else {
                currentStreak = 0;
            }
        }

        return maxStreak;
    }

    public static void main(String[] args) {
        System.out.println(findMaxConsecutiveOnes(new int[]{1, 1, 0, 1, 1, 1})); // 3
        System.out.println(findMaxConsecutiveOnes(new int[]{1, 0, 1, 1, 0, 1})); // 2
    }
}
