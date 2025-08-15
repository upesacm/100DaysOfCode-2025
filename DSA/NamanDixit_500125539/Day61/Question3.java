import java.util.*;

class Question3 {
    int[] arr;
    int size;

    public Question3(int arr[]) {
        this.arr = arr;
        this.size = arr.length;
        buildHeap();
    }

    // Build a max heap from the array
    void buildHeap() {
        for (int i = this.size / 2 - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    // Heapify a subtree with root at root_index
    void heapify(int root_index) {
        int max_index = root_index;
        int left = root_index * 2 + 1;
        int right = root_index * 2 + 2;

        if (left < size && arr[left] > arr[max_index]) {
            max_index = left;
        }
        if (right < size && arr[right] > arr[max_index]) {
            max_index = right;
        }

        if (max_index != root_index) {
            int temp = arr[root_index];
            arr[root_index] = arr[max_index];
            arr[max_index] = temp;

            heapify(max_index);
        }
    }

    // Heap sort function
    void heapSort() {
        for (int i = size - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            size--; // reduce the heap size
            heapify(0);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.print("Enter elements: ");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        Question3 heap = new Question3(arr);
        heap.heapSort();
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();

        sc.close();
    }
}
