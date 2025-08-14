public class IsMaxHeap {
    public static boolean isMaxHeap(int[] arr) {
        int n = arr.length;
        for (int i = 0; i <= (n - 2) / 2; i++) { // only check non-leaf nodes
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && arr[i] < arr[left]) return false;
            if (right < n && arr[i] < arr[right]) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println(isMaxHeap(new int[]{90, 15, 10, 7, 12, 2})); // true
        System.out.println(isMaxHeap(new int[]{9, 15, 10, 7, 12, 2}));  // false
    }
}
