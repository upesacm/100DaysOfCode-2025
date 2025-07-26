import java.util.*;
public class RemoveKDigits 
{
    public static String removeKdigits(String num, int k) 
  {
        Stack<Character> stack = new Stack<>();
        for (char digit : num.toCharArray()) 
        {
            while (!stack.isEmpty() && k > 0 && stack.peek() > digit) 
            {
                stack.pop();
                k--;
            }
            stack.push(digit);
        }
        while (k > 0 && !stack.isEmpty()) 
        {
            stack.pop();
            k--;
        }
        StringBuilder result = new StringBuilder();
        for (char digit : stack) 
        {
            result.append(digit);
        }
        while (result.length() > 0 && result.charAt(0) == '0') 
        {
            result.deleteCharAt(0);
        }
        return result.length() == 0 ? "0" : result.toString();
    }
    public static void main(String[] args) 
  {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a non-negative integer: ");
        String num = scanner.nextLine();
        System.out.print("Enter the number of digits to remove (k): ");
        int k = scanner.nextInt();
        String smallest = removeKdigits(num, k);
        System.out.println("Smallest possible number after removing " + k + " digits: " + smallest);
    }
}
