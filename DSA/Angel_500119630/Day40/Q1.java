class Q1 {
    public int celebrity(int[][] mat) {
         int n = mat.length;
        int a = 0, b = n - 1;

        while (a < b) {
            if (mat[a][b] == 1) {
                a++;
            } else {
                b--;
            }
        }

        int cand = a;

        for (int i = 0; i < n; i++) {
            if (i != cand) {
                if (mat[cand][i] == 1 || mat[i][cand] == 0) {
                    return -1; 
                }
            }
        }

        return cand; 
    }
}
