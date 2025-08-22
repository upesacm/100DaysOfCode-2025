public class Q2 {
    public static boolean isMaxHeap(int[] arr) {
        int n = arr.length;

        // Only need to check non-leaf nodes
        for (int i = 0; i <= (n / 2) - 1; i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            // Check left child
            if (left < n && arr[i] < arr[left]) {
                return false;
            }
            // Check right child
            if (right < n && arr[i] < arr[right]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        int[] arr1 = {90, 15, 10, 7, 12, 2, 7};
        int[] arr2 = {9, 15, 10, 7, 12, 2, 7};

        System.out.println(isMaxHeap(arr1)); 
        System.out.println(isMaxHeap(arr2)); 
    }
}
