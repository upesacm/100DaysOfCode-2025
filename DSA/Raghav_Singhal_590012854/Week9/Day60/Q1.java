class Q1 {
    static class MinHeap {
        int[] heap;
        int size;
        int capacity;

        MinHeap(int capacity) {
            this.capacity = capacity;
            this.size = 0;
            this.heap = new int[capacity];
        }

        int parent(int i) { return (i - 1) / 2; }
        int left(int i) { return 2 * i + 1; }
        int right(int i) { return 2 * i + 2; }

        void swap(int i, int j) {
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
        }

        void insert(int val) {
            if (size == capacity) {
                throw new RuntimeException("Heap overflow");
            }
            heap[size] = val;
            int curr = size;
            size++;

            while (curr > 0 && heap[parent(curr)] > heap[curr]) {
                swap(curr, parent(curr));
                curr = parent(curr);
            }
        }

        int extractMin() {
            if (size <= 0) return Integer.MAX_VALUE;
            if (size == 1) {
                size--;
                return heap[0];
            }

            int root = heap[0];
            heap[0] = heap[size - 1];
            size--;
            heapify(0);
            return root;
        }

        void heapify(int i) {
            int l = left(i);
            int r = right(i);
            int smallest = i;

            if (l < size && heap[l] < heap[smallest]) smallest = l;
            if (r < size && heap[r] < heap[smallest]) smallest = r;

            if (smallest != i) {
                swap(i, smallest);
                heapify(smallest);
            }
        }
    }

    public static void sortKSorted(int[] arr, int k) {
        int n = arr.length;
        MinHeap mh = new MinHeap(k + 1);

        int i = 0;
        for (; i < k + 1 && i < n; i++) {
            mh.insert(arr[i]);
        }

        int index = 0;
        for (; i < n; i++) {
            arr[index++] = mh.extractMin();
            mh.insert(arr[i]);
        }

        while (mh.size > 0) {
            arr[index++] = mh.extractMin();
        }
    }

    public static void main(String[] args) {
        int[] arr = {6, 5, 3, 2, 8, 10, 9};
        int k = 3;

        sortKSorted(arr, k);
                                                                                                                                                                                                            
        for (int val : arr) {
            System.out.print(val + " ");
        }
    }
}
