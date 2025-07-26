import java.util.*;

public class Question1 {

    public static int getCelebrity(int[][] arr, int n) {
        Stack<Integer> s = new Stack<>();

        // Step 1: Push all people to stack
        for (int i = 0; i < n; i++) {
            s.push(i);
        }

        // Step 2: Eliminate non-celebrities
        while (s.size() > 1) {
            int a = s.pop();
            int b = s.pop();

            // If a knows b → a can't be celebrity
            if (arr[a][b] == 1) {
                s.push(b);
            } else {
                s.push(a);
            }
        }

        // Step 3: Verify the potential celebrity
        int celeb = s.pop();

        for (int i = 0; i < n; i++) {
            if (i != celeb) {
                // celeb must not know anyone and everyone must know celeb
                if (arr[celeb][i] == 1 || arr[i][celeb] == 0) {
                    return -1;
                }
            }
        }

        return celeb;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of people: ");
        int n = sc.nextInt();

        int[][] arr = new int[n][n];
        System.out.println("Enter the matrix (row by row):");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        int result = getCelebrity(arr, n);
        System.out.println(result);

        sc.close();
    }
}
