import java.util.*;

public class Question1 {
    static class MinHeap {
        private ArrayList<Integer> heap;

        public MinHeap() {
            heap = new ArrayList<>();
        }

        private void swap(int i, int j) {
            int temp = heap.get(i);
            heap.set(i, heap.get(j));
            heap.set(j, temp);
        }

        private void heapifyUp(int index) {
            while (index > 0) {
                int parent = (index - 1) / 2;
                if (heap.get(index) < heap.get(parent)) {
                    swap(index, parent);
                    index = parent;
                } else {
                    break;
                }
            }
        }

        private void heapifyDown(int index) {
            int size = heap.size();
            while (true) {
                int left = 2 * index + 1;
                int right = 2 * index + 2;
                int smallest = index;

                if (left < size && heap.get(left) < heap.get(smallest)) {
                    smallest = left;
                }
                if (right < size && heap.get(right) < heap.get(smallest)) {
                    smallest = right;
                }
                if (smallest != index) {
                    swap(index, smallest);
                    index = smallest;
                } else {
                    break;
                }
            }
        }

        public void insert(int val) {
            heap.add(val);
            heapifyUp(heap.size() - 1);
        }

        public int extractMin() {
            if (heap.isEmpty()) return -1;
            int min = heap.get(0);
            heap.set(0, heap.get(heap.size() - 1));
            heap.remove(heap.size() - 1);
            heapifyDown(0);
            return min;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        MinHeap minHeap = new MinHeap();

        System.out.print("Enter number of operations: ");
        int n = sc.nextInt();
        sc.nextLine(); // consume newline

        for (int i = 0; i < n; i++) {
            System.out.print("Enter operation (insert X / extractMin): ");
            String input = sc.nextLine().trim();

            if (input.startsWith("insert")) {
                int value = Integer.parseInt(input.split(" ")[1]);
                minHeap.insert(value);
            } else if (input.equalsIgnoreCase("extractMin")) {
                int min = minHeap.extractMin();
                if (min != -1) {
                    System.out.println("Extracted Min: " + min);
                } else {
                    System.out.println("Heap is empty!");
                }
            } else {
                System.out.println("Invalid operation!");
            }
        }

        sc.close();
    }
}
