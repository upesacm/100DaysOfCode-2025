import java.util.*;
class Day37Question2
{
    public static int evalPostfix(String s)
    {
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s.charAt(i);

            if (Character.isDigit(ch))
            {
                stack.push(ch - '0'); 
            }
            else
            {
                int y = stack.pop();
                int x = stack.pop();
                int result = 0;

                switch (ch)
                {
                    case '+': result = x + y; break;
                    case '-': result = x - y; break;
                    case '*': result = x * y; break;
                    case '/': result = x / y; break;
                }
                stack.push(result);
            }
        }

        return stack.pop();
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter postfix expression:");
        String str = sc.nextLine();

        int result = evalPostfix(str);
        System.out.println("Output: " + result);
    }
}

