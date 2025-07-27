import java.util.*;
class Day40Question1 
{
    public static boolean result(int[][] M, int a, int b) 
    {
        return M[a][b] == 1;
    }

    public static int find(int[][] M, int n) 
    {
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < n; i++) 
        {
            stack.push(i);
        }

        while (stack.size() > 1) 
        {
            int a = stack.pop();
            int b = stack.pop();

            if (result(M, a, b)) 
            {
                stack.push(b);
            } 
            else 
            {
                stack.push(a);
            }
        }

        int candidate = stack.pop();
        for (int i = 0; i < n; i++) 
        {
            if (i != candidate && (result(M, candidate, i) || !result(M, i, candidate))) 
            {
                return -1;
            }
        }

        return candidate;
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of people: ");
        int n = sc.nextInt();

        int[][] M = new int[n][n];

        System.out.println("Enter elements of the matrix (0 or 1):");
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                M[i][j] = sc.nextInt();
            }
        }

        int finalAns = find(M, n);
        if (finalAns == -1) 
        {
            System.out.println("-1");
        } 
        else 
        {
            System.out.println("Output: " + finalAns);
        }

        sc.close();
    }
}

