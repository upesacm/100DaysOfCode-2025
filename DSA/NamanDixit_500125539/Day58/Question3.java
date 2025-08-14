import java.util.*;

public class Question3 {

    // Sift-down to restore max-heap property from index i
    private static void siftDown(int[] heap, int size, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != i) {
            swap(heap, i, largest);
            siftDown(heap, size, largest);
        }
    }

    // Swap helper
    private static void swap(int[] heap, int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input heap size
        int n = sc.nextInt();
        int[] heap = new int[n];

        // Input heap elements
        for (int i = 0; i < n; i++) {
            heap[i] = sc.nextInt();
        }

        // Input new root element
        int newElement = sc.nextInt();

        // Replace root with new element
        heap[0] = newElement;

        // Restore heap property
        siftDown(heap, n, 0);

        // Output according to example
        System.out.println("New heap with root replaced and heap property maintained");

        sc.close();
    }
}
