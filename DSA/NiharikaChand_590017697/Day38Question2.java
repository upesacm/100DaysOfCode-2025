import java.util.*;
class Day38Question2 
{
    Stack<Integer> stack = new Stack<>();
    Stack<Integer> minStack = new Stack<>();

    void push(int x) 
    {
        stack.push(x);

        if (minStack.isEmpty() || x <= minStack.peek()) 
        {
            minStack.push(x);
        }
    }

    void pop() 
    {
        if (stack.isEmpty()) 
        {
            System.out.println("Stack is empty. Cannot pop.");
            return;
        }

        int removed = stack.pop();
        if (removed == minStack.peek()) 
        {
            minStack.pop();
        }
    }

    int top() 
    {
        if (stack.isEmpty()) 
        {
            System.out.println("Stack is empty. No top element.");
            return -1;
        }
        return stack.peek();
    }

    int getMin() 
    {
        if (minStack.isEmpty()) 
        {
            System.out.println("Stack is empty. No minimum element.");
            return -1;
        }
        return minStack.peek();
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        Day38Question2 ms = new Day38Question2();

        System.out.print("Enter number of operations: ");
        int n = sc.nextInt();
        sc.nextLine(); 

        System.out.println("Enter push <val>, pop, top, min");

        for (int i = 0; i < n; i++) 
        {
            String cmd[] = sc.nextLine().split(" ");

            if (cmd[0].equals("push")) 
            {
                if (cmd.length < 2) 
                {
                    System.out.println("Error: push needs a value.");
                    continue;
                }
                try {
                    int val = Integer.parseInt(cmd[1]);
                    ms.push(val);
                } 
                catch (NumberFormatException e) 
                {
                    System.out.println("Error: invalid number format.");
                }
            } 
            else if (cmd[0].equals("pop")) 
            {
                ms.pop();
            } 
            else if (cmd[0].equals("top")) 
            {
                System.out.println("Top: " + ms.top());
            } 
            else if (cmd[0].equalsIgnoreCase("min"))
            {
                System.out.println("Min: " + ms.getMin());
            } 
            else 
            {
                System.out.println("Invalid command.");
            }
        }
    }
}
