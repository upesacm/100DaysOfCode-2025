import java.util.*;
class Day40Question3
{
    Stack<Integer> mainStack = new Stack<>();
    Stack<Integer> maxStack = new Stack<>();

    public void push(int val) 
    {
        mainStack.push(val);
        if (maxStack.isEmpty() || val >= maxStack.peek()) 
        {
            maxStack.push(val);
        }
    }

    public void pop() 
    {
        if (mainStack.isEmpty()) 
        {
            System.out.println("Stack is empty.");
            return;
        }
        int removed = mainStack.pop();
        if (removed == maxStack.peek()) 
        {
            maxStack.pop();
        }
    }

    public int getMax() 
    {
        if (maxStack.isEmpty()) 
        {
            System.out.println("Stack is empty.");
            return -1;
        }
        return maxStack.peek();
    }

    public void display() 
    {
        System.out.println("Current Stack: " + mainStack);
        System.out.println("Current Max: " + getMax());
    }

    public static void main(String args[]) 
    {
        Day40Question3 stack = new Day40Question3();
        Scanner sc = new Scanner(System.in);

        while (true) 
        {
            System.out.println("\n1. Push\n2. Pop\n3. Get Max\n4. Display\n5. Exit");
            System.out.print("Enter choice: ");
            int choice = sc.nextInt();

            switch (choice) 
            {
                case 1:
                    System.out.print("Enter value to push: ");
                    int val = sc.nextInt();
                    stack.push(val);
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    System.out.println("Max Element: " + stack.getMax());
                    break;
                case 4:
                    stack.display();
                    break;
                case 5:
                    System.out.println("Exiting...");
                    sc.close();
                    return;
                default:
                    System.out.println("Invalid choice.");
            }
        }
    }
}

