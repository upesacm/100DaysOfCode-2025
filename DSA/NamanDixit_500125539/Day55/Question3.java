import java.util.*;

public class Question3 {

    // Function to count subarrays with sum at most 'goal'
    public static int atMost(int[] nums, int goal) {
        int i = 0, j = 0, ans = 0, sum = 0, n = nums.length;

        while (j < n) {
            sum += nums[j];

            while (sum > goal && i <= j) {
                sum -= nums[i];
                i++;
            }

            ans += j - i + 1;
            j++;
        }

        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        int[] nums = new int[n];

        System.out.println("Enter the elements (0s and 1s for binary array case):");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        System.out.print("Enter goal: ");
        int goal = sc.nextInt();

        int result = atMost(nums, goal);
        System.out.println(result);

        sc.close();
    }
}
