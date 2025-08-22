import java.util.*;

public class ReplaceRootInHeap {
    public static void replaceRoot(int[] heap, int newElement) {
        if (heap.length == 0) return;

        heap[0] = newElement; // replace root
        heapify(heap, heap.length, 0);
    }

    private static void heapify(int[] arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;

        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            heapify(arr, n, largest);
        }
    }

    public static void main(String[] args) {
        int[] heap1 = {50, 30, 20, 15, 10, 8, 16};
        replaceRoot(heap1, 25);
        System.out.println(Arrays.toString(heap1));

        int[] heap2 = {100, 80, 70, 60, 50, 40, 30};
        replaceRoot(heap2, 35);
        System.out.println(Arrays.toString(heap2));
    }
}
