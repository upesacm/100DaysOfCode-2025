import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Question1 {

    public static void subArraySum(int[] a, int sum) {
        int curSum = 0;
        int start = 0;
        int end = -1;
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < a.length; i++) {
            curSum += a[i];

            // Case 1: Subarray starts from index 0
            if (curSum - sum == 0) {
                start = 0;
                end = i;
                break;
            }

            // Case 2: Subarray found in between
            if (map.containsKey(curSum - sum)) {
                start = map.get(curSum - sum) + 1;
                end = i;
                break;
            }

            // Store the current sum with index
            map.put(curSum, i);
        }

        if (end == -1) {
            System.out.println("Not Found");
        } else {
            System.out.println(end - start + 1); // length of subarray
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.print("Enter the target sum: ");
        int sum = sc.nextInt();

        subArraySum(arr, sum);

        sc.close();
    }
}
