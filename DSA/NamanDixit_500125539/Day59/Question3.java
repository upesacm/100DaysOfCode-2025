import java.util.*;

public class Question3 {

    // Check if an array is a valid max-heap
    public static boolean isMaxHeap(int[] arr) {
        int n = arr.length;
        for (int i = 0; i <= (n - 2) / 2; i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && arr[i] < arr[left]) return false;
            if (right < n && arr[i] < arr[right]) return false;
        }
        return true;
    }

    // Check if two heaps are equal and both are valid max-heaps
    public static boolean areHeapsEqual(int[] arr1, int[] arr2) {
        if (arr1.length != arr2.length) return false;

        // Check heap property for both
        if (!isMaxHeap(arr1) || !isMaxHeap(arr2)) return false;

        // Check element equality in the same order
        for (int i = 0; i < arr1.length; i++) {
            if (arr1[i] != arr2[i]) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input first heap
        System.out.print("Enter size of first heap: ");
        int n1 = sc.nextInt();
        int[] arr1 = new int[n1];
        System.out.println("Enter elements of first heap:");
        for (int i = 0; i < n1; i++) arr1[i] = sc.nextInt();

        // Input second heap
        System.out.print("Enter size of second heap: ");
        int n2 = sc.nextInt();
        int[] arr2 = new int[n2];
        System.out.println("Enter elements of second heap:");
        for (int i = 0; i < n2; i++) arr2[i] = sc.nextInt();

        // Check and print result
        System.out.println(areHeapsEqual(arr1, arr2));
    }
}
