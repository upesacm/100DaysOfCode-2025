import java.util.*;
class Day39Question1 
{
    public static void insert(Stack<Integer> stack, int el) 
    {
        if (stack.isEmpty()) 
        {
            stack.push(el);
            return;
        }

        int top = stack.pop();
        insert(stack, el);
        stack.push(top);
    }

    public static void reverse(Stack<Integer> stack) 
    {
        if (stack.isEmpty()) 
        {
            return;
        }
        int top = stack.pop();
        reverse(stack);
        insert(stack, top);
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Stack<Integer> stk = new Stack<>();

        System.out.println("Enter number of elements in the stack:");
        int n = sc.nextInt();

        System.out.println("Enter elements in top to bottom manner: ");
        for (int i = 0; i < n; i++) 
        {
            int num = sc.nextInt();
            stk.push(num);
        }

        reverse(stk);
        System.out.println("Output:");
        while (!stk.isEmpty()) 
        {
            System.out.print(stk.pop() + " ");
        }
    }
}

