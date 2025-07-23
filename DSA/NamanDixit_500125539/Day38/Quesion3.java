
import java.util.*;

public class Question3 {

    public static boolean checkRedundantBrackets(String expression) {
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < expression.length(); i++) {
            char ch = expression.charAt(i);

            if (ch == ')') {
                char top = stack.pop();
                boolean isRedundant = true;

                while (top != '(') {
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    top = stack.pop();
                }

                if (isRedundant) {
                    return true;
                }
            } else {
                stack.push(ch);
            }
        }

        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter an expression: ");
        String expression = sc.nextLine();

        boolean result = checkRedundantBrackets(expression);
        System.out.println(result);

        sc.close();
    }
}
