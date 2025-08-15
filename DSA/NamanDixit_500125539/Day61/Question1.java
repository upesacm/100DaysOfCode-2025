import java.util.*;

public class Question1 {

    public static void convertMinToMaxHeap(int[] arr, int N) {
        for (int i = (N - 2) / 2; i >= 0; i--) {
            maxHeapify(arr, i, N);
        }
    }

    public static void maxHeapify(int[] arr, int i, int N) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < N && arr[left] > arr[largest])
            largest = left;

        if (right < N && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            maxHeapify(arr, largest, N);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements: ");
        int N = sc.nextInt();

        int[] arr = new int[N];
        System.out.print("Enter elements of Min Heap: ");
        for (int i = 0; i < N; i++) {
            arr[i] = sc.nextInt();
        }

        convertMinToMaxHeap(arr, N);

        System.out.print("Max Heap: ");
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();

        sc.close();
    }
}
