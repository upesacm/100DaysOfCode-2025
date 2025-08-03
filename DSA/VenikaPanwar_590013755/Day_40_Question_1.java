import java.util.Scanner;
import java.util.Stack;

public class Day_40_Question_1 {

    static boolean knows(int[][] matrix, int a, int b) {
        return matrix[a][b] == 1;
    }

    static int findCelebrity(int[][] matrix, int n) {
        Stack<Integer> stack = new Stack<>();

        // Push all people into stack
        for (int i = 0; i < n; i++) stack.push(i);

        // Eliminate non-celebrities
        while (stack.size() > 1) {
            int a = stack.pop();
            int b = stack.pop();

            if (knows(matrix, a, b)) {
                // a cannot be celebrity
                stack.push(b);
            } else {
                // b cannot be celebrity
                stack.push(a);
            }
        }

        // Final candidate
        int candidate = stack.pop();

        // Validate candidate
        for (int i = 0; i < n; i++) {
            if (i != candidate && (matrix[candidate][i] == 1 || matrix[i][candidate] == 0)) {
                return -1;
            }
        }

        return candidate;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of people: ");
        int n = sc.nextInt();

        int[][] matrix = new int[n][n];
        System.out.println("Enter matrix:");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                matrix[i][j] = sc.nextInt();

        int result = findCelebrity(matrix, n);
        System.out.println("Celebrity Index: " + result);
    }
}
