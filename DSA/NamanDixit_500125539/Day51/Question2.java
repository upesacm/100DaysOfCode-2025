import java.util.*;

public class Question2 {

    public static int minSubArrayLen(int target, int[] nums) {
        int minLenWindow = Integer.MAX_VALUE;
        int currentSum = 0;
        int low = 0, high = 0;

        while (high < nums.length) {
            currentSum += nums[high];
            high++;

            while (currentSum >= target) {
                int currentWindowSize = high - low;
                minLenWindow = Math.min(minLenWindow, currentWindowSize);
                currentSum -= nums[low];
                low++;
            }
        }

        return (minLenWindow == Integer.MAX_VALUE) ? 0 : minLenWindow;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int[] nums = new int[n];
        System.out.println("Enter elements of array:");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        System.out.print("Enter target sum: ");
        int target = sc.nextInt();

        int result = minSubArrayLen(target, nums);
        System.out.println(result);

        sc.close();
    }
}
