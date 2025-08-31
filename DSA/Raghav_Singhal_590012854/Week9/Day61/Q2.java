class Q2 {
    static class MaxHeap {
        int[] heap;
        int size;
        int capacity;

        MaxHeap(int capacity) {
            this.capacity = capacity;
            this.size = 0;
            this.heap = new int[capacity + 1]; 
        }

        public void insert(int val) {
            if (size == capacity) {
                System.out.println("Heap is full!");
                return;
            }
            heap[++size] = val;  
            bubbleUp(size);       
        }

        private void bubbleUp(int index) {
            while (index > 1 && heap[index / 2] < heap[index]) {
                swap(index, index / 2);
                index = index / 2;
            }
        }

        public int deleteRoot() {
            if (size == 0) {
                System.out.println("Heap is empty!");
                return -1;
            }
            int root = heap[1];
            heap[1] = heap[size--]; 
            heapifyDown(1);       
            return root;
        }

        private void heapifyDown(int index) {
            int largest = index;
            int left = 2 * index, right = 2 * index + 1;

            if (left <= size && heap[left] > heap[largest]) largest = left;
            if (right <= size && heap[right] > heap[largest]) largest = right;

            if (largest != index) {
                swap(index, largest);
                heapifyDown(largest);
            }
        }

        private void swap(int i, int j) {
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
        }

        public void printHeap() {
            for (int i = 1; i <= size; i++) {
                System.out.print(heap[i] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        MaxHeap h = new MaxHeap(20);

        h.insert(20);
        h.insert(15);
        h.insert(8);
        System.out.print("Heap after inserts: ");
        h.printHeap();

        h.deleteRoot();
        System.out.print("Heap after deleting root: ");
        h.printHeap();

        h = new MaxHeap(20); 
        h.insert(30);
        h.insert(25);
        h.insert(10);
        h.insert(35);
        System.out.print("\nHeap after inserts: ");
        h.printHeap();

        h.deleteRoot();
        System.out.print("Heap after deleting root: ");
        h.printHeap();

        h.insert(40);
        System.out.print("Heap after inserting 40: ");
        h.printHeap();
    }
}
