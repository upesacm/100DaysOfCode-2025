import java.util.*;
class Day38Question3 
{
    public static boolean checkRedundantBrk(String expr) 
    {
        Stack<Character> stack = new Stack<>();

        for (char ch : expr.toCharArray()) 
        {
            if (ch == ')') 
            {
                boolean opFound = false;

                while (!stack.isEmpty() && stack.peek() != '(') 
                {
                    char top = stack.pop();
                    if (top == '+' || top == '-' || top == '*' || top == '/') 
                    {
                        opFound = true;
                    }
                }

                if (!stack.isEmpty()) 
                {
                    stack.pop(); 
                }

                if (!opFound) 
                {
                    return true;
                }
            } 
            else 
            {
                stack.push(ch);
            }
        }

        return false;
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter expression: ");
        String expr = sc.nextLine();

        if (checkRedundantBrk(expr)) 
        {
            System.out.println("Yes");
        } 
        else 
        {
            System.out.println("No");
        }
    }
}

