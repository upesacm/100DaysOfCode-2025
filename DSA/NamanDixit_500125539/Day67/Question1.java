import java.util.*;

public class Question1 {

    // Function to arrange numbers for maximum concatenated value
    public static String largestNumber(int[] nums) {
        // Convert int[] to String[]
        String[] arr = new String[nums.length];
        for (int i = 0; i < nums.length; i++) {
            arr[i] = String.valueOf(nums[i]);
        }

        // Custom comparator: decide order based on concatenation
        Arrays.sort(arr, (a, b) -> (b + a).compareTo(a + b));

        // Edge case: if the largest number is "0", return "0"
        if (arr[0].equals("0")) {
            return "0";
        }

        // Build final answer
        StringBuilder result = new StringBuilder();
        for (String s : arr) {
            result.append(s);
        }
        return result.toString();
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

        String result = largestNumber(nums);
        System.out.println(result);

        sc.close();
    }
}
