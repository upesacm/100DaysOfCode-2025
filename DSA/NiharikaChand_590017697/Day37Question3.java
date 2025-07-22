import java.util.*;
class Day37Question3
{
    public static void deleteMid(Stack<Integer> stk, int curr, int mid)
    {
        if (stk.isEmpty() || curr == mid)
        {
            stk.pop(); 
            return;
        }

        int temp = stk.pop();
        deleteMid(stk, curr + 1, mid);
        stk.push(temp); 
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        Stack<Integer> stack = new Stack<>();

        System.out.println("Enter number of elements:");
        int n = sc.nextInt();
        
        for (int i = 0; i < n; i++)
        {
            System.out.println("Enter an element:");
            stack.push(sc.nextInt());
        }

        int mid = n / 2;
        deleteMid(stack, 0, mid);

        System.out.println("Output: " + stack);
    }
}

