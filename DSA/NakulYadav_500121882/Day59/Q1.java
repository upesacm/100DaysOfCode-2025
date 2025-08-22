import java.util.*;
public class Q1 {
    int[] heap;
    int size;
    Q1(int capacity) {
        heap = new int[capacity];
        size = 0;
    }
    void insert(int val) {
        heap[size] = val;
        int current = size;
        while (current > 0 && heap[current] < heap[(current - 1) / 2]) {
            int temp = heap[current];
            heap[current] = heap[(current - 1) / 2];
            heap[(current - 1) / 2] = temp;
            current = (current - 1) / 2;
        }
        size++;
    }
    int extractMin() {
        if (size == 0) return -1;
        int min = heap[0];
        heap[0] = heap[size - 1];
        size--;
        int current = 0;
        while (true) {
            int left = 2 * current + 1;
            int right = 2 * current + 2;
            int smallest = current;
            if (left < size && heap[left] < heap[smallest]) smallest = left;
            if (right < size && heap[right] < heap[smallest]) smallest = right;
            if (smallest != current) {
                int temp = heap[current];
                heap[current] = heap[smallest];
                heap[smallest] = temp;
                current = smallest;
            } else break;
        }
        return min;
    }
    public static void main(String[] args) {
        Q1 minHeap = new Q1(10);
        minHeap.insert(3);
        minHeap.insert(2);
        minHeap.insert(15);
        System.out.println(minHeap.extractMin());
    }
}
