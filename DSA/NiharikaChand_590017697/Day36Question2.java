import java.util.*;
class Day36Question2 
{
    public static void checkBalanced(String s) 
    {
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) 
        {
            char ch = s.charAt(i);
            if (ch == '(' || ch == '{' || ch == '[') 
            {
                stack.push(ch);
            }
            else if (ch == ')' || ch == '}' || ch == ']') 
            {
                if (stack.isEmpty()) 
                {
                    System.out.println("Not Balanced");
                    return;
                }
                
                char top = stack.pop();
                if (!check(top, ch)) 
                {
                    System.out.println("Not Balanced");
                    return;
                }
            }
        }
        if (stack.isEmpty()) 
        {
            System.out.println("Balanced");
        } 
        else 
        {
            System.out.println("Not Balanced");
        }
    }

    public static boolean check(char open, char close) 
    {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String s = sc.nextLine();
        checkBalanced(s);
    }
}

