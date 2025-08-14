public class Q2 {

    // Function to heapify a subtree rooted at index i (max-heap)
    static void heapify(int[] arr, int n, int i) {
        int largest = i;      
        int left = 2 * i + 1; 
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            heapify(arr, n, largest);
        }
    }
    static void buildMaxHeap(int[] arr) {
        int n = arr.length;
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }

    public static void main(String[] args) {
        int[] arr = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};

        System.out.println("Original Array:");
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();

        buildMaxHeap(arr);

        System.out.println("Max Heap:");
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }
}
