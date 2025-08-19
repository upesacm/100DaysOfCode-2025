class Q3 {
    static void heapify(int arr[], int n, int i) {
        int largest = i;          
        int left = 2 * i + 1;    
        int right = 2 * i + 2;  

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            heapify(arr, n, largest);
        }
    }

    static void heapSort(int arr[]) {
        int n = arr.length;

        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        for (int i = n - 1; i > 0; i--) {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;

            heapify(arr, i, 0);
        }
    }

    static void printArray(int arr[]) {
        for (int num : arr)
            System.out.print(num + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        int arr1[] = {4, 10, 3, 5, 1};
        System.out.print("Original: ");
        printArray(arr1);
        heapSort(arr1);
        System.out.print("Sorted:   ");
        printArray(arr1);

        int arr2[] = {12, 11, 13, 5, 6, 7};
        System.out.print("\nOriginal: ");
        printArray(arr2);
        heapSort(arr2);
        System.out.print("Sorted:   ");
        printArray(arr2);
    }
}
