import java.util.*;
public class Q2 {
    public static List<int[]> findPairsWithDifference(int[] arr, int k) {
        Set<Integer> set = new HashSet<>();
        Set<String> seen = new HashSet<>();
        List<int[]> result = new ArrayList<>();
        for (int num : arr) set.add(num);
        for (int num : arr) {
            if (set.contains(num + k)) {
                String key = num + "," + (num + k);
                if (!seen.contains(key)) {
                    result.add(new int[]{num, num + k});
                    seen.add(key);
                }
            }
            if (set.contains(num - k)) {
                String key = num + "," + (num - k);
                if (!seen.contains(key)) {
                    result.add(new int[]{num, num - k});
                    seen.add(key);
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int[] arr = {1, 5, 3, 4, 2};
        int k = 2;
        List<int[]> pairs = findPairsWithDifference(arr, k);
        for (int[] pair : pairs) {
            System.out.print("(" + pair[0] + ", " + pair[1] + ") ");
        }
    }
}
