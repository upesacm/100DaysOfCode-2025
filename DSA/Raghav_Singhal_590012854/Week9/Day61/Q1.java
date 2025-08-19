import java.util.*;

public class Q1 {

    private static void heapify(int arr[], int n, int i) {
        int largest = i; 
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            heapify(arr, n, largest);
        }
    }

    public static void convertToMaxHeap(int arr[]) {
        int n = arr.length;

        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }

    public static void main(String[] args) {
        int arr[] = {1, 3, 5, 7, 9, 2}; 
        System.out.println("Original Min Heap: " + Arrays.toString(arr));

        convertToMaxHeap(arr);

        System.out.println("Converted Max Heap: " + Arrays.toString(arr));
    }
}
