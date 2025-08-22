public class Q3 {

    private static void heapify(int[] heap, int n, int i) {
        int largest = i; // Assume current node is largest
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < n && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != i) {
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;

            heapify(heap, n, largest);
        }
    }
    public static void replaceRoot(int[] heap, int newValue) {
        heap[0] = newValue; 
        heapify(heap, heap.length, 0);
    }

    public static void printHeap(int[] heap) {
        for (int val : heap) {
            System.out.print(val + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] heap = {50, 30, 20, 15, 10, 8, 16};
        int newElement = 25;

        System.out.println("Original Heap:");
        printHeap(heap);

        replaceRoot(heap, newElement);

        System.out.println("Heap after replacing root with " + newElement + ":");
        printHeap(heap);
    }
}
