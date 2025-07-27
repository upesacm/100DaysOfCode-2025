import java.util.*;
public class DecodeString 
{
    public static String decodeString(String s) 
  {
        Stack<Integer> countStack = new Stack<>();
        Stack<StringBuilder> stringStack = new Stack<>();
        StringBuilder currentStr = new StringBuilder();
        int k = 0;
        for (char ch : s.toCharArray()) 
        {
            if (Character.isDigit(ch)) 
            {
                k = k * 10 + (ch - '0');
            } else if (ch == '[') 
            {
                countStack.push(k);
                stringStack.push(currentStr);
                k = 0;
                currentStr = new StringBuilder();
            } else if (ch == ']') 
            {
                int repeatCount = countStack.pop();
                StringBuilder prevStr = stringStack.pop();
                StringBuilder temp = new StringBuilder(prevStr);
                for (int i = 0; i < repeatCount; i++) {
                    temp.append(currentStr);
                }
                currentStr = temp;
            } 
            else 
            {
                currentStr.append(ch);
            }
        }
        return currentStr.toString();
    }
    public static void main(String[] args) 
  {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter encoded string (e.g., 3[a]2[bc]): ");
        String input = scanner.nextLine();
        String decoded = decodeString(input);
        System.out.println("Decoded string: " + decoded);
    }
}
