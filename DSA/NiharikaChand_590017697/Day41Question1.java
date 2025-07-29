import java.util.*;
class Day41Question1  
{
    public static String removeOnce(String s) 
    {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) 
        {
            char ch = s.charAt(i);
            if (!stack.isEmpty() && stack.peek() == ch) 
            {
                stack.pop();
            } 
            else 
            {
                stack.push(ch);
            }
        }

        StringBuilder result = new StringBuilder();
        for (int i = 0; i < stack.size(); i++) 
        {
            result.append(stack.get(i));
        }
        return result.toString();
    }

    public static String remove(String s) 
    {
        String prev;
        do 
        {
            prev = s;
            s = removeOnce(s);
        } while (!s.equals(prev));
        return s;
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String input = sc.nextLine();

        String result = remove(input);
        System.out.println("Output: " + result);
        sc.close();
    }
}

