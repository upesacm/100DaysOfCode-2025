import java.util.Arrays;
import java.util.Scanner;

public class Q2 {

    public static int findMaxChain(int[][] pairs) {
        Arrays.sort(pairs, (a, b) -> Integer.compare(a[1], b[1]));

        System.out.println("\nSorted Pairs by end coordinate:");
        for (int[] pair : pairs) {
            System.out.print("(" + pair[0] + ", " + pair[1] + ") ");
        }
        System.out.println("\n");

        int count = 1;
        int lastEnd = pairs[0][1];
        System.out.println("Selected pair: (" + pairs[0][0] + ", " + pairs[0][1] + ")");

        for (int i = 1; i < pairs.length; i++) {
            if (pairs[i][0] > lastEnd) {
                count++;
                lastEnd = pairs[i][1];
                System.out.println("Selected pair: (" + pairs[i][0] + ", " + pairs[i][1] + ")");
            } else {
                System.out.println("Skipped pair:  (" + pairs[i][0] + ", " + pairs[i][1] + ")");
            }
        }

        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of pairs: ");
        int n = sc.nextInt();
        int[][] pairs = new int[n][2];

        System.out.println("Enter pairs (a b): ");
        for (int i = 0; i < n; i++) {
            pairs[i][0] = sc.nextInt();
            pairs[i][1] = sc.nextInt();
        }

        // Find maximum chain length
        int maxChain = findMaxChain(pairs);

        System.out.println("\nMaximum length of chain = " + maxChain);
        sc.close();
    }
}
