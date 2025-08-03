import java.util.*;
public class RemoveAdjacentDuplicates 
{
    public static String removeOnce(String s) 
  {
        Stack<Character> stack = new Stack<>();
        for (char ch : s.toCharArray()) 
        {
            if (!stack.isEmpty() && stack.peek() == ch) 
            {
                stack.pop();
            } else 
            {
                stack.push(ch);
            }
        }
        StringBuilder sb = new StringBuilder();
        for (char ch : stack) 
        {
            sb.append(ch);
        }
        return sb.toString();
    }
    public static String removeAllAdjacentDuplicates(String s) 
  {
        String prev;
        String curr = s;
        do 
        {
            prev = curr;
            curr = removeOnce(prev);
       } 
          while (!prev.equals(curr));
        return curr;
    }
    public static void main(String[] args) 
  {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String input = scanner.nextLine();
        String result = removeAllAdjacentDuplicates(input);
        System.out.println("Result after removing all adjacent duplicates: " + result);
    }
}
