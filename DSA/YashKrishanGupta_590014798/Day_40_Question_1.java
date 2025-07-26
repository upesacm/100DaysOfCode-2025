import java.util.*;
public class Day_40_Question_1 {
    static boolean knows(int[][] M, int a, int b) {
        return M[a][b] == 1;
    }

    static int findCelebrity(int[][] M) {
        int n = M.length;
        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < n; i++) {
            st.push(i);
        }

        while (st.size() > 1) {
            int A = st.pop();
            int B = st.pop();

            if (knows(M, A, B)) {
                st.push(B);
            } else {
                st.push(A);
            }
        }

        if (st.isEmpty()) {
            return -1;
        }

        int candidate = st.pop();

        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                if (knows(M, candidate, i) || !knows(M, i, candidate)) {
                    return -1;
                }
            }
        }
        return candidate;
    }

    public static void main(String[] args) {
        int[][] M = {
                {0, 1, 1},
                {0, 0, 1},
                {0, 0, 0}
        };

        int celeb = findCelebrity(M);
        if (celeb == -1) {
            System.out.println("No celebrity found");
        } else {
            System.out.println("Celebrity is person " + celeb);
        }
    }
}
