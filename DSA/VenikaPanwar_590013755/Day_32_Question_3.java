import java.util.*;

public class Day_32_Question_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter the array elements:");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        int result = 0;
        for (int val : arr) result ^= val;

        System.out.println("XOR of all elements: " + result);
    }
}
