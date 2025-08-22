import java.util.*;

public class MaxHeapOperations {
    private List<Integer> heap = new ArrayList<>();

    public void insert(int value) {
        heap.add(value);
        int i = heap.size() - 1;
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap.get(i) > heap.get(parent)) {
                Collections.swap(heap, i, parent);
                i = parent;
            } else break;
        }
    }

    public int deleteRoot() {
        if (heap.isEmpty()) throw new NoSuchElementException("Heap is empty");
        int root = heap.get(0);
        int last = heap.remove(heap.size() - 1);
        if (!heap.isEmpty()) {
            heap.set(0, last);
            siftDown(0);
        }
        return root;
    }

    private void siftDown(int i) {
        int size = heap.size();
        while (true) {
            int left = 2 * i + 1, right = 2 * i + 2;
            int largest = i;

            if (left < size && heap.get(left) > heap.get(largest)) largest = left;
            if (right < size && heap.get(right) > heap.get(largest)) largest = right;

            if (largest != i) {
                Collections.swap(heap, i, largest);
                i = largest;
            } else break;
        }
    }

    public void printHeap() {
        System.out.println(heap);
    }

    public static void main(String[] args) {
        MaxHeapOperations h1 = new MaxHeapOperations();
        h1.insert(20);
        h1.insert(15);
        h1.insert(8);
        h1.deleteRoot();
        h1.printHeap();

        MaxHeapOperations h2 = new MaxHeapOperations();
        h2.insert(30);
        h2.insert(25);
        h2.insert(10);
        h2.insert(35);
        h2.deleteRoot();
        h2.insert(40);
        h2.printHeap();
    }
}
