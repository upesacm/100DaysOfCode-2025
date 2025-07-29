import java.util.*;
class Day41Question3
{
    public static String remove(String num, int k) 
    {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < num.length(); i++) 
        {
            char ch = num.charAt(i);
            while (!stack.isEmpty() && k > 0 && stack.peek() > ch) 
            {
                stack.pop();
                k--;
            }
            stack.push(ch);
        }

        while (k > 0 && !stack.isEmpty()) 
        {
            stack.pop();
            k--;
        }

        StringBuilder result = new StringBuilder();
        for (int i = 0; i < stack.size(); i++) 
        {
            result.append(stack.get(i));
        }

        while (result.length() > 1 && result.charAt(0) == '0') 
        {
            result.deleteCharAt(0);
        }
        if (result.length() == 0) 
        {
            return "0";
        }   
        else 
        {
            return result.toString();
        }
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        String num = sc.nextLine();

        System.out.print("Enter k (digits to remove): ");
        int k = sc.nextInt();

        String result = remove(num, k);
        System.out.println("Smallest number: " + result);
        sc.close();
    }
}

