
class Q2 {
    static class MaxHeap {
        int[] heap;
        int size;

        MaxHeap(int n) {
            heap = new int[n];
            size = 0;
        }

        void insert(int val) {
            heap[size] = val;
            int i = size;
            size++;
            while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
                swap(i, (i - 1) / 2);
                i = (i - 1) / 2;
            }
        }

        int extractMax() {
            if (size == 0) return -1;
            int root = heap[0];
            heap[0] = heap[size - 1];
            size--;
            heapify(0);
            return root;
        }

        int peek() {
            return size == 0 ? -1 : heap[0];
        }

        void heapify(int i) {
            int largest = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;

            if (l < size && heap[l] > heap[largest]) largest = l;
            if (r < size && heap[r] > heap[largest]) largest = r;

            if (largest != i) {
                swap(i, largest);
                heapify(largest);
            }
        }

        void swap(int i, int j) {
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
        }

        int getSize() {
            return size;
        }
    }

    static class MinHeap {
        int[] heap;
        int size;

        MinHeap(int n) {
            heap = new int[n];
            size = 0;
        }

        void insert(int val) {
            heap[size] = val;
            int i = size;
            size++;
            while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
                swap(i, (i - 1) / 2);
                i = (i - 1) / 2;
            }
        }

        int extractMin() {
            if (size == 0) return -1;
            int root = heap[0];
            heap[0] = heap[size - 1];
            size--;
            heapify(0);
            return root;
        }

        int peek() {
            return size == 0 ? -1 : heap[0];
        }

        void heapify(int i) {
            int smallest = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;

            if (l < size && heap[l] < heap[smallest]) smallest = l;
            if (r < size && heap[r] < heap[smallest]) smallest = r;

            if (smallest != i) {
                swap(i, smallest);
                heapify(smallest);
            }
        }

        void swap(int i, int j) {
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
        }

        int getSize() {
            return size;
        }
    }

    static MaxHeap left = new MaxHeap(1000); 
    static MinHeap right = new MinHeap(1000); 

    static void insertNum(int num) {
        if (left.getSize() == 0 || num <= left.peek()) {
            left.insert(num);
        } else {
            right.insert(num);
        }

        // Balance
        if (left.getSize() > right.getSize() + 1) {
            right.insert(left.extractMax());
        } else if (right.getSize() > left.getSize()) {
            left.insert(right.extractMin());
        }
    }

    static int getMedian() {
        if (left.getSize() == right.getSize()) {
            return (left.peek() + right.peek()) / 2;
        } else {
            return left.peek();
        }
    }

    public static void main(String[] args) {
        int[] stream = {5, 15, 1, 3};
        for (int num : stream) {
            insertNum(num);
            System.out.print(getMedian() + " ");
        }
    }
}
