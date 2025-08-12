import java.util.*;

public class CheckIdenticalHeaps {
    public static boolean areHeapsIdentical(int[] heap1, int[] heap2) {
        if (heap1.length != heap2.length) return false;
        for (int i = 0; i < heap1.length; i++) {
            if (heap1[i] != heap2[i]) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        int[] arr1 = {10, 9, 8};
        int[] arr2 = {10, 9, 8};
        int[] arr3 = {10, 8, 9};

        System.out.println(areHeapsIdentical(arr1, arr2)); // true
        System.out.println(areHeapsIdentical(arr1, arr3)); // false
    }
}
