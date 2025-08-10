import java.util.Scanner;

public class Question3 {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1) return 0;

        int i = 0, j = 0;
        int prod = 1;
        int count = 0;

        while (j < nums.length) {
            prod *= nums[j];

            while (prod >= k) {
                prod /= nums[i];
                i++;
            }

            count += (j - i + 1);
            j++;
        }

        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        int[] nums = new int[n];

        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }

        System.out.print("Enter value of k: ");
        int k = sc.nextInt();

        Question3 obj = new Question3();
        int result = obj.numSubarrayProductLessThanK(nums, k);
        System.out.println(result);
    }
}
