import java.util.*;

public class Day_38_Question_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter expression: ");
        String expr = sc.nextLine();

        boolean isRedundant = checkRedundant(expr);
        System.out.println(isRedundant ? "Yes" : "No");
    }

    static boolean checkRedundant(String expr) {
        Stack<Character> stack = new Stack<>();

        for (char ch : expr.toCharArray()) {
            if (ch == ')') {
                boolean hasOperator = false;
                while (!stack.isEmpty() && stack.peek() != '(') {
                    char top = stack.pop();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        hasOperator = true;
                    }
                }
                if (!stack.isEmpty()) stack.pop(); // Remove '('
                if (!hasOperator) return true; // No operator inside ()
            } else {
                stack.push(ch);
            }
        }

        return false;
    }
}
