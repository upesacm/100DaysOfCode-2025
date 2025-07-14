import java.util.*;
public class Q3 {
    public static void main(String[] args) {
        int arr[]={64, 34, 25, 12, 22, 11, 90};
        System.out.println(Arrays.toString(bubbleSort(arr)));
    }
    public static int[] bubbleSort(int[] arr) {
        int n = arr.length;
        boolean check;
        for (int i = 0; i < n - 1; i++) {
            check = false;
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    check = true;
                }
            }
            if (!check)
                break;
        }
        return arr;
    }
}