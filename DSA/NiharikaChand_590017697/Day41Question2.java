import java.util.*;
class Day41Question2  
{
    public static String decode(String s) 
    {
        Stack<Integer> countStack = new Stack<>();
        Stack<StringBuilder> stringStack = new Stack<>();
        StringBuilder curr = new StringBuilder();
        int k = 0;

        for (int i = 0; i < s.length(); i++) 
        {
            char ch = s.charAt(i);

            if (Character.isDigit(ch)) 
            {
                k = k * 10 + (ch - '0'); 
            } 
            else if (ch == '[') 
            {
                countStack.push(k);             
                stringStack.push(curr);      
                curr = new StringBuilder();  
                k = 0;                           
            } 
            else if (ch == ']') 
            {
                int repeat = countStack.pop();
                StringBuilder previous = stringStack.pop();
                for (int j = 0; j < repeat; j++) 
                {
                    previous.append(curr);
                }
                curr = previous; 
            } 
            else 
            {
                curr.append(ch); 
            }
        }
        return curr.toString();
    }

    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter encoded string: ");
        String input = sc.nextLine();

        String result = decode(input);
        System.out.println("Output: " + result);
        sc.close();
    }
}

