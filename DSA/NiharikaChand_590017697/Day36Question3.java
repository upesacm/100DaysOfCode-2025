import java.util.*;
class Day36Question3 
{
    public static void insert(Stack<Integer> stack, int x) 
    {
        if (stack.isEmpty()) 
        {
            stack.push(x); 
            return;
        }

        int top = stack.pop();
        insert(stack, x);

        stack.push(top);
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Stack<Integer> stack = new Stack<>();
        System.out.println("Enter number of elements in stack:");
        int n = sc.nextInt();
    
        for (int i = 0; i < n; i++) 
        {
            System.out.println("Enter an element: ");
            stack.push(sc.nextInt());
        }

        System.out.println("Enter the element to insert at bottom: ");
        int s = sc.nextInt();

        insert(stack, s);
        System.out.println("Output: " + stack);
    }
}

