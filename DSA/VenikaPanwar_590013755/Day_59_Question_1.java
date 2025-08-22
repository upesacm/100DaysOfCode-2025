import java.util.*;

class MinHeap {
    private List<Integer> heap;

    public MinHeap() {
        heap = new ArrayList<>();
    }

    private void bubbleUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap.get(index) < heap.get(parent)) {
                Collections.swap(heap, index, parent);
                index = parent;
            } else {
                break;
            }
        }
    }

    private void bubbleDown(int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && heap.get(left) < heap.get(smallest)) smallest = left;
            if (right < size && heap.get(right) < heap.get(smallest)) smallest = right;

            if (smallest != index) {
                Collections.swap(heap, index, smallest);
                index = smallest;
            } else break;
        }
    }

    public void insert(int value) {
        heap.add(value);
        bubbleUp(heap.size() - 1);
    }

    public int extractMin() {
        if (heap.isEmpty()) throw new NoSuchElementException("Heap is empty");
        int min = heap.get(0);
        int last = heap.remove(heap.size() - 1);
        if (!heap.isEmpty()) {
            heap.set(0, last);
            bubbleDown(0);
        }
        return min;
    }
}

public class MinHeapDemo {
    public static void main(String[] args) {
        MinHeap h1 = new MinHeap();
        h1.insert(3);
        h1.insert(2);
        h1.insert(15);
        System.out.println(h1.extractMin()); // 2

        MinHeap h2 = new MinHeap();
        h2.insert(10);
        h2.insert(5);
        h2.insert(20);
        h2.insert(8);
        System.out.println(h2.extractMin()); // 5
        System.out.println(h2.extractMin()); // 8
    }
}
