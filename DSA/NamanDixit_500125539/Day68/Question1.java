import java.util.Scanner;

public class Question1 {

    // Function to find minimum jumps to reach the end
    public static int jump(int[] nums) {
        int totalJumps = 0;
        int destination = nums.length - 1;
        int coverage = 0, lastJumpIdx = 0;

        // Base case
        if (nums.length == 1) return 0;

        // Greedy strategy: extend coverage as long as possible
        for (int i = 0; i < nums.length; i++) {
            coverage = Math.max(coverage, i + nums[i]);

            if (i == lastJumpIdx) {
                lastJumpIdx = coverage;
                totalJumps++;

                // check if we reached destination already
                if (coverage >= destination) {
                    return totalJumps;
                }
            }
        }
        return totalJumps;
    }

    // Main function
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int[] nums = new int[n];
        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        int result = jump(nums);
        System.out.println(result);
    }
}
