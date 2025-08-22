import java.util.*;

public class Q3 {
    public static void heapify(int[] arr, int n, int i) {
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

    public static void replaceRoot(int[] arr, int newElement) {
        arr[0] = newElement;
        heapify(arr, arr.length, 0);
    }

    public static void main(String[] args) {
        int[] arr = {50, 30, 20, 15, 10, 8, 16};
        replaceRoot(arr, 25);
        System.out.println(Arrays.toString(arr)); // New heap with root replaced
    }
}
