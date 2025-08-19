import java.util.*;

public class Question2 {
    public static int findLongestChain(int[][] pairs) {
        int cur = Integer.MIN_VALUE, res = 0;
        
        // Sort by second element of each pair
        Arrays.sort(pairs, (a, b) -> {
            return a[1] - b[1];
        });
        
        for (int[] pair : pairs) {
            if (cur < pair[0]) {
                cur = pair[1];
                res++;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input number of pairs
        System.out.print("Enter number of pairs: ");
        int n = sc.nextInt();

        int[][] pairs = new int[n][2];

        // Input each pair
        for (int i = 0; i < n; i++) {
            pairs[i][0] = sc.nextInt();
            pairs[i][1] = sc.nextInt();
        }

        // Call function
        int result = findLongestChain(pairs);
        System.out.println(result);

        sc.close();
    }
}
