import java.util.*;

public class Question2 {

    private static ArrayList<Integer> heap = new ArrayList<>();

    // Bubble-up to maintain max-heap property after insertion
    private static void bubbleUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap.get(index) > heap.get(parent)) {
                swap(index, parent);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Sift-down to maintain max-heap property after deletion
    private static void siftDown(int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap.get(left) > heap.get(largest))
                largest = left;
            if (right < size && heap.get(right) > heap.get(largest))
                largest = right;

            if (largest != index) {
                swap(index, largest);
                index = largest;
            } else {
                break;
            }
        }
    }

    // Swap helper
    private static void swap(int i, int j) {
        int temp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, temp);
    }

    // Insert element into heap
    public static void insert(int value) {
        heap.add(value);
        bubbleUp(heap.size() - 1);
    }

    // Delete root from heap
    public static void deleteRoot() {
        if (heap.size() == 0) return;
        heap.set(0, heap.get(heap.size() - 1));
        heap.remove(heap.size() - 1);
        siftDown(0);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter operations (insert X / delete / end):");
        while (true) {
            String op = sc.next();
            if (op.equalsIgnoreCase("insert")) {
                int value = sc.nextInt();
                insert(value);
            } else if (op.equalsIgnoreCase("delete")) {
                deleteRoot();
            } else if (op.equalsIgnoreCase("end")) {
                break;
            }
        }

        System.out.println("Heap after operations: " + heap);
        sc.close();
    }
}
