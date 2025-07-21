import java.util.Scanner;
import java.util.Stack;

public class Question2 {

    // Function to check if brackets are balanced
    static boolean isValid(String str) {
        Stack<Character> st = new Stack<>();

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch); // Push opening bracket
            } else {
                if (st.isEmpty()) {
                    return false; // No opening bracket to match
                }
                char top = st.peek();
                if ((top == '(' && ch == ')') ||
                    (top == '{' && ch == '}') ||
                    (top == '[' && ch == ']')) {
                    st.pop(); // Matching pair
                } else {
                    return false; // Mismatched
                }
            }
        }

        return st.isEmpty(); // True if all brackets matched
    }

    public static void balanceBrackets(String str) {
        if (isValid(str)) {
            System.out.println("True");
        } else {
            System.out.println("False");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter String: ");
        String str = sc.nextLine();
        balanceBrackets(str);
    }
}
