class Q1 {
    public int minCut(String s) {
        int n = s.length();
        boolean[][] isPal = new boolean[n][n];

        // Palindrome DP precomputation
        for (int i = 0; i < n; i++) {
            isPal[i][i] = true;
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s.charAt(i) == s.charAt(j)) {
                    if (len == 2) isPal[i][j] = true;
                    else isPal[i][j] = isPal[i + 1][j - 1];
                }
            }
        }

        // DP for min cuts
        int[] cuts = new int[n];
        for (int i = 0; i < n; i++) {
            if (isPal[0][i]) {
                cuts[i] = 0;
            } else {
                cuts[i] = i; // worst case
                for (int j = 0; j < i; j++) {
                    if (isPal[j + 1][i]) {
                        cuts[i] = Math.min(cuts[i], cuts[j] + 1);
                    }
                }
            }
        }
        return cuts[n - 1];
    }

    public static void main(String[] args) {
        Q1 obj = new Q1();
        System.out.println(obj.minCut("aab")); // Output: 1
        System.out.println(obj.minCut("a"));   // Output: 0
    }
}
