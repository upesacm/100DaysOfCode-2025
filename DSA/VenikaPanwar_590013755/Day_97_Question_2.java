public class Day_97_Question_2 {

    // Longest Palindromic Subsequence using DP
    public static int longestPalindromeSubseq(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];
        // Single characters are palindromes of length 1
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        // Fill dp for substrings of length >= 2
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = 2 + (len == 2 ? 0 : dp[i + 1][j - 1]);
                } else {
                    dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return n == 0 ? 0 : dp[0][n - 1];
    }

    public static void main(String[] args) {
        System.out.println(longestPalindromeSubseq("bbbab")); // Output: 4
        System.out.println(longestPalindromeSubseq("cbbd"));  // Output: 2
        System.out.println(longestPalindromeSubseq("a"));     // Output: 1
    }
}
