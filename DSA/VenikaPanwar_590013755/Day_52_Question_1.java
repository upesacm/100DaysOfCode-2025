import java.util.*;

public class PairSum {
    public static boolean hasPairWithSum(int[] arr, int x) {
        Arrays.sort(arr); // Ensure the array is sorted
        int left = 0, right = arr.length - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == x) return true;
            else if (sum < x) left++;
            else right--;
        }

        return false;
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 4, 45, 6, 10, 8};
        int x1 = 16;
        System.out.println("Output 1: " + hasPairWithSum(arr1, x1)); // true

        int[] arr2 = {1, 2, 4, 3, 6};
        int x2 = 10;
        System.out.println("Output 2: " + hasPairWithSum(arr2, x2)); // false
    }
}
