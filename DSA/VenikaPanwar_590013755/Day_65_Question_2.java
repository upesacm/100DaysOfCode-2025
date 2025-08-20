import java.util.*;

public class MaxChainPairs {
    public static int maxChain(int[][] pairs) {
        Arrays.sort(pairs, Comparator.comparingInt(a -> a[1]));
        int count = 1;
        int lastEnd = pairs[0][1];

        for (int i = 1; i < pairs.length; i++) {
            if (pairs[i][0] > lastEnd) {
                count++;
                lastEnd = pairs[i][1];
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int[][] pairs1 = {{5, 24}, {15, 25}, {27, 40}, {50, 60}};
        System.out.println(maxChain(pairs1)); // 3

        int[][] pairs2 = {{1, 2}, {2, 3}, {3, 4}};
        System.out.println(maxChain(pairs2)); // 2
    }
}
