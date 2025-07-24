import java.util.*;

public class Question1 {
    public static int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        Stack<Integer> stack = new Stack<>();

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            int num = nums[i];
            while (!stack.isEmpty() && stack.peek() <= num) {
                stack.pop();
            }

            result[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(num);
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input nums
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int[] nums = new int[n];

        System.out.println("Enter elements of the array:");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        // Get next greater elements
        int[] result = nextGreaterElements(nums);

        // Output result
            for (int val : result) {
            System.out.print(val + " ");
        }

        sc.close();
    }
}
