import java.util.*;

public class Q2 {

    public static List<int[]> findPairsWithDifference(int[] arr, int k) {
        Set<Integer> seen = new HashSet<>();
        List<int[]> result = new ArrayList<>();

        for (int num : arr) {
            if (seen.contains(num - k)) {
                result.add(new int[]{num, num - k});
            }
            if (seen.contains(num + k)) {
                result.add(new int[]{num, num + k});
            }
            seen.add(num);
        }

        return result;
    }

    public static void printPairs(List<int[]> pairs) {
        for (int[] pair : pairs) {
            System.out.println(Arrays.toString(pair));
        }
    }

    public static void main(String[] args) {
        int[] arr = {1, 5, 3, 4, 2};
        int k = 2;

        List<int[]> pairs = findPairsWithDifference(arr, k);
        printPairs(pairs); 
    }
}
