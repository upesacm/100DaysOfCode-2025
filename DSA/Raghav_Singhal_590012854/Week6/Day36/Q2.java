import java.util.*;
public class Q2 {

    public static String isBalanced(String str) {
        Stack<Character> stack = new Stack<>();

        for (char ch : str.toCharArray()) {
            if (ch == '(' || ch == '{' || ch == '[')
                stack.push(ch);
            else if (ch == ')' || ch == '}' || ch == ']') {
                if (stack.isEmpty()) return "Not Balanced";

                char top = stack.pop();
                if (!isMatchingPair(top, ch)) return "Not Balanced";
            }
        }

        return stack.isEmpty()?"Balanced":"Not Balanced";
    }

    static boolean isMatchingPair(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }

    public static void main(String[] args) {

        String str1 = "([])";
        String str2 = "([";

        System.out.println(isBalanced(str1));
        System.out.println(isBalanced(str2));
    }
}
