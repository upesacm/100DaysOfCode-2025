import java.util.*;
public class Q1 {
    public static boolean hasPairWithSum(int[] arr, int x) {
        Arrays.sort(arr);
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
        int[] arr = {1, 4, 45, 6, 10, 8};
        int x = 16;
        System.out.println(hasPairWithSum(arr, x));
    }
}
