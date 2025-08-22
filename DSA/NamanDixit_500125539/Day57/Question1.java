import java.util.*;

public class Question1 {

    private static int partition(int[] nums, int left, int right, int pivotIndex) {
        int pivot = nums[pivotIndex];
        swap(nums, pivotIndex, right);
        int storedIndex = left;
        for (int i = left; i < right; i++) {
            if (nums[i] < pivot) { // Partition by smaller elements
                swap(nums, i, storedIndex);
                storedIndex++;
            }
        }
        swap(nums, right, storedIndex);
        return storedIndex;
    }

    private static void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    private static void quickSelect(int[] nums, int left, int right, int kSmallest) {
        if (left == right) return;

        int pivotIndex = left + (right - left) / 2;
        pivotIndex = partition(nums, left, right, pivotIndex);

        if (kSmallest == pivotIndex) {
            return;
        } else if (kSmallest < pivotIndex) {
            quickSelect(nums, left, pivotIndex - 1, kSmallest);
        } else {
            quickSelect(nums, pivotIndex + 1, right, kSmallest);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        int k = sc.nextInt();
        
        int kSmallestIndex = n - k; // kth largest is (n-k) smallest index
        quickSelect(nums, 0, n - 1, kSmallestIndex);
        
        int[] result = new int[k];
        System.arraycopy(nums, n - k, result, 0, k);
        
        Arrays.sort(result);
        for (int i = k - 1; i >= 0; i--) {
            System.out.print(result[i]);
            if (i > 0) System.out.print(" ");
        }
    }
}
