public class Q1 {

    static void buildMinHeap(int[] arr, int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }

    static void heapify(int[] arr, int n, int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] < arr[smallest])
            smallest = left;

        if (right < n && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != i) {
            // Swap
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;

            heapify(arr, n, smallest);
        }
    }

    static int kthSmallest(int[] arr, int k) {
        int n = arr.length;

        buildMinHeap(arr, n);

        for (int i = 0; i < k - 1; i++) {
            int temp = arr[0];
            arr[0] = arr[n - 1];
            arr[n - 1] = temp;

            n--; 
            heapify(arr, n, 0);
        }

        return arr[0]; 
    }

    public static void main(String[] args) {
        int[] arr1 = {7, 10, 4, 3, 20, 15};
        int k1 = 3;
        System.out.println(kthSmallest(arr1, k1)); 

        int[] arr2 = {7, 10, 4, 20, 15};
        int k2 = 4;
        System.out.println(kthSmallest(arr2, k2)); 
    }
}
