import java.util.Scanner;
import java.util.Stack;

public class Day_36_Question_2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string of brackets: ");
        String input = sc.nextLine();

        Stack<Character> stack = new Stack<>();
        boolean balanced = true;

        for (char ch : input.toCharArray()) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            } else if (ch == ')' || ch == '}' || ch == ']') {
                if (stack.isEmpty()) {
                    balanced = false;
                    break;
                }
                char top = stack.pop();
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    balanced = false;
                    break;
                }
            }
        }

        if (balanced && stack.isEmpty())
            System.out.println("Balanced");
        else
            System.out.println("Not Balanced");
    }
}
