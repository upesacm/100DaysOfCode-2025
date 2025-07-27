import java.util.Stack;

public class Q1 {

    public static int findCelebrity(int[][] M) {
        int n = M.length;
        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < n; i++) st.push(i);

        while (st.size() > 1) {
            int a = st.pop();
            int b = st.pop();

            if (knows(M, a, b)) {
                st.push(b);
            } else {
                st.push(a);
            }
        }

        int cand = st.pop();

        for (int i = 0; i < n; i++) {
            if (i == cand) continue;
            if (knows(M, cand, i) || !knows(M, i, cand)) {
                return -1;
            }
        }
        return cand;
    }

    private static boolean knows(int[][] M, int a, int b) {
        return M[a][b] == 1;
    }

    public static void main(String[] args) {
        int[][] M1 = {
            {0,1,1},
            {0,0,1},
            {0,0,0}
        };
        System.out.println(findCelebrity(M1)); 
    }
}
