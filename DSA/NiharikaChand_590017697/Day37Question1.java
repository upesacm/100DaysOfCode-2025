import java.util.*;
class Day37Question1
{
    public static void sort(Stack<Integer> stack)
    {
        Stack<Integer> tempStk = new Stack<>();

        while (!stack.isEmpty())
        {
            int temp = stack.pop();
            while (!tempStk.isEmpty() && tempStk.peek() < temp)
            {
                stack.push(tempStk.pop());
            }
            tempStk.push(temp);
        }

        
        while (!tempStk.isEmpty())
        {
            stack.push(tempStk.pop());
        }
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

        sort(stack);
        System.out.println("Output" + stack);
    }
}
