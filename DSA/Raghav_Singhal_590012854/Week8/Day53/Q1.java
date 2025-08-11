public class Q1 {

    public static int findMaxConsecutiveOnes(int[] nums) {
        int maxStreak = 0;
        int currentStreak = 0;

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
        int[] binaryArray = {1, 1, 0, 1, 1, 1};
        int result = findMaxConsecutiveOnes(binaryArray);
        System.out.println("Max Consecutive Ones: " + result);
    }
}
