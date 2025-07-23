import java.util.*;
class Day36Question1 
{
    public static void LIFO(String s) 
    {
        Stack<Character> stk = new Stack<>();
        for (int i = 0; i < s.length(); i++) 
        {
            stk.push(s.charAt(i));
        }

        while (!stk.isEmpty()) 
        {
            System.out.print(stk.pop());
        }
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String s = sc.nextLine();
        LIFO(s);
    }
}

