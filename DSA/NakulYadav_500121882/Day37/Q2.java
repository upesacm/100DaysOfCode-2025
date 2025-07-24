import java.util.*;

public class Q2 {
    public static void main(String[] args) {
        String expression = "231*+9-";
        int result = evaluatePostfix(expression);
        System.out.println("Result: " + result);
    }

    static int evaluatePostfix(String exp) {
        Stack<Integer> stack = new Stack<>();

        for (char c : exp.toCharArray()) {
            if (Character.isDigit(c)) {
                stack.push(c - '0');
            } else {
                int b = stack.pop();
                int a = stack.pop();

                switch (c) {
                    case '+': stack.push(a + b); break;
                    case '-': stack.push(a - b); break;
                    case '*': stack.push(a * b); break;
                    case '/': stack.push(a / b); break;
                }
            }
        }
        return stack.pop();
    }
}
