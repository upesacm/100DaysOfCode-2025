import java.util.*;
public class Q3 {
    static boolean areHeapsIdentical(int[] heap1, int[] heap2) {
        if (heap1.length != heap2.length) return false;
        for (int i = 0; i < heap1.length; i++) {
            if (heap1[i] != heap2[i]) return false;
        }
        return true;
    }
    public static void main(String[] args) {
        int[] heap1 = {10, 9, 8};
        int[] heap2 = {10, 9, 8};
        System.out.println(areHeapsIdentical(heap1, heap2));
    }
}
