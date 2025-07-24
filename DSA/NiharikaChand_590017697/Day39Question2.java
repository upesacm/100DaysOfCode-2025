import java.util.*;
class Day39Question2
{
    public static int[] calSpan(int p[]) 
    {
        int n = p.length;
        int span[] = new int[n];
        Stack<Integer> stk = new Stack<>();

        for (int i = 0; i < n; i++) 
        {
            while (!stk.isEmpty() && p[stk.peek()] <= p[i]) 
            {
                stk.pop();
            }

            if (stk.isEmpty()) 
            {
                span[i] = i + 1;
            }   
            else 
            {
                span[i] = i - stk.peek();
            }
            stk.push(i);
        }

        return span;
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of days:");
        int n = sc.nextInt();
        int p[] = new int[n];

        System.out.println("Enter stock prices:");
        for (int i = 0; i < n; i++) 
        {
            p[i] = sc.nextInt();
        }

        int span[] = calSpan(p);

        System.out.println("Output:");
        for (int i = 0; i < span.length; i++) 
        {
            System.out.print(span[i] + " ");
        }
    }
}

