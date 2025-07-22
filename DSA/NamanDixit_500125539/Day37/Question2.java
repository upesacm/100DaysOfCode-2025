import java.util.Scanner;
import java.util.Stack;

public class Question2 {

    public int postfixEvaluation(String s) {
        Stack<Integer> st = new Stack<>();
        int x, y;
        char ch[] = s.toCharArray();

        for (char c : ch) {
            if (c >= '0' && c <= '9') {
                st.push(c - '0');
            } else {
                y = st.pop();
                x = st.pop();
                switch (c) {
                    case '+':
                        st.push(x + y);
                        break;
                    case '-':
                        st.push(x - y);
                        break;
                    case '*':
                        st.push(x * y);
                        break;
                    case '/':
                        st.push(x / y);
                        break;
                }
            }
        }

        return st.pop();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Question2 evaluator = new Question2();

        System.out.print("Enter postfix expression (e.g., 231*+9-): ");
        String expr = sc.next();

        int result = evaluator.postfixEvaluation(expr);
        System.out.println("Result: " + result);
    }
}
