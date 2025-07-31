import java.util.*;
public class Q3 {

    public static String hasRedundantBrackets(String expr) {
        Stack<Character> stack = new Stack<>();

        for (char ch : expr.toCharArray()) {
            if (ch == ')') {
                boolean hasOperator = false;
                while (!stack.isEmpty() && stack.peek() != '(') {
                    char top = stack.pop();
                    if ((top == '+' || top == '-' || top == '*' || top == '/')) {
                        hasOperator = true;
                    }
                }
                stack.pop();
                if (!hasOperator) {
                    return "Yes";
                }

            } else {
                stack.push(ch);
            }
        }
        return "No";
    }

    public static void main(String[] args) {
        String expr = "((a+b))";

        System.out.println(hasRedundantBrackets(expr));
    }
}
