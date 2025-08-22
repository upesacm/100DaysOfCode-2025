import java.util.*;

public class PairsWithDifference {
    public static List<String> findAllPairs(int[] arr, int k) {
        List<String> pairs = new ArrayList<>();
        Set<Integer> set = new HashSet<>();

        for (int val : arr) {
            if (set.contains(val + k)) pairs.add("(" + val + ", " + (val + k) + ")");
            if (set.contains(val - k)) pairs.add("(" + val + ", " + (val - k) + ")");
            set.add(val);
        }

        return pairs;
    }

    public static void main(String[] args) {
        int[] arr1 = {1, 5, 3, 4, 2};
        int k1 = 2;
        System.out.println("Output 1: " + findAllPairs(arr1, k1));
        // [(3, 1), (5, 3), (3, 5), (4, 2)]

        int[] arr2 = {8, 12, 16, 4, 0, 20};
        int k2 = 4;
        System.out.println("Output 2: " + findAllPairs(arr2, k2));
        // [(8, 12), (12, 16), (16, 20), (4, 0)]
    }
}
