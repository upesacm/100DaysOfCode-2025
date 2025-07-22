import java.util.Scanner;
import java.util.Stack;

public class Day_37_Question_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter postfix expression (e.g., 231*+9-): ");
        String expr = sc.nextLine();

        int result = evaluatePostfix(expr);
        System.out.println("Result: " + result);
    }

    static int evaluatePostfix(String expr) {
        Stack<Integer> stack = new Stack<>();

        for (char ch : expr.toCharArray()) {
            if (Character.isDigit(ch)) {
                stack.push(ch - '0');
            } else {
                int b = stack.pop();
                int a = stack.pop();

                switch (ch) {
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
