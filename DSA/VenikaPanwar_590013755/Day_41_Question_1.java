import java.util.Scanner;
import java.util.Stack;

public class Day_41_Question_1 {
    public static String removeDuplicates(String s) {
        Stack<Character> stack = new Stack<>();
        for (char ch : s.toCharArray()) {
            if (!stack.isEmpty() && stack.peek() == ch) {
                stack.pop(); // remove adjacent duplicate
            } else {
                stack.push(ch);
            }
        }

        // Build the final result
        StringBuilder result = new StringBuilder();
        for (char ch : stack) {
            result.append(ch);
        }

        return result.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter string: ");
        String input = sc.nextLine();

        String output = removeDuplicates(input);
        System.out.println("Reduced string: " + output);
    }
}
