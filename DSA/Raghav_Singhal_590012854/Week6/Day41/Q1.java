import java.util.Stack;

public class Q1 {

    public static String removeAdjacentDuplicates(String s) {
        Stack<Character> stack = new Stack<>();

        for (char c : s.toCharArray()) 
            if (!stack.isEmpty() && stack.peek() == c) 
                stack.pop();  
            else
                stack.push(c);  

        StringBuilder result = new StringBuilder();
        for (char c : stack)
            result.append(c);

        return result.toString();
    }

    public static void main(String[] args) {
        String input1 = "abbaca";
        String input2 = "azxxzy";
        System.out.println(removeAdjacentDuplicates(input1));
        System.out.println(removeAdjacentDuplicates(input2));
    }
}
