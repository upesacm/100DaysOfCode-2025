import java.util.*;

public class Question3 {
    public static int findSmallestMissingNonNegative(int[] arr) {
        Set<Integer> set = new HashSet<>();
        for (int num : arr) {
            set.add(num);
        }

        int i = 0;
        while (true) {
            if (!set.contains(i)) {
                return i;
            }
            i++;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter array length: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int result = findSmallestMissingNonNegative(arr);
        System.out.println(result);
    }
}
