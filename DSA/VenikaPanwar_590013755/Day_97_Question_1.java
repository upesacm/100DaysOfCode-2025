public class Day_97_Question_1 {

    // Palindrome Partitioning (Min Cuts) using DP
    public static int minCut(String s) {
        int n = s.length();
        boolean[][] isPal = new boolean[n][n];
        // Precompute palindrome substrings
        for (int end = 0; end < n; end++) {
            for (int start = 0; start <= end; start++) {
                if (s.charAt(start) == s.charAt(end) &&
                    (end - start <= 2 || isPal[start + 1][end - 1])) {
                    isPal[start][end] = true;
                }
            }
        }
        // cuts[i]: min cuts for s[0..i]
        int[] cuts = new int[n];
        for (int i = 0; i < n; i++) {
            if (isPal[0][i]) {
                cuts[i] = 0;
            } else {
                cuts[i] = i;
                for (int j = 1; j <= i; j++) {
                    if (isPal[j][i]) {
                        cuts[i] = Math.min(cuts[i], cuts[j - 1] + 1);
                    }
                }
            }
        }
        return n == 0 ? 0 : cuts[n - 1];
    }

    public static void main(String[] args) {
        System.out.println(minCut("aab")); // Output: 1
        System.out.println(minCut("a"));   // Output: 0
        System.out.println(minCut("abccbc")); // Output: 2
    }
}
