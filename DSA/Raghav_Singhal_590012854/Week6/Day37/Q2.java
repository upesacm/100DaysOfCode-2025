import java.util.*;

public class Q2 {

    public static int evaluatePostfix(String expr) {
        Stack<Integer> stack = new Stack<>();
        
        for (int i = 0; i < expr.length(); i++) {
            char ch = expr.charAt(i);

            if (Character.isDigit(ch)) {
                stack.push(ch - '0');
            } else if (isOperator(ch)) {
                int b = stack.pop();
                int a = stack.pop();
                int result = applyOperator(a, b, ch);
                stack.push(result);
            }
        }
        return stack.pop();
    }

    private static boolean isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }

    private static int applyOperator(int a, int b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default: throw new IllegalArgumentException("Invalid operator: " + op);
        }
    }

    public static void main(String[] args) {
        String expr = "231/+9-";
        System.out.println(evaluatePostfix(expr));
    }
}
