import java.util.Stack;

public class Q1 {
    public static String reverse(String input) {
        Stack<Character> stack = new Stack<>();

        for (char ch : input.toCharArray()) {
            stack.push(ch);
        }

        StringBuilder reversed = new StringBuilder();
        while (!stack.isEmpty()) {
            reversed.append(stack.pop());
        }

        return reversed.toString();
    }

    public static void main(String[] args) {
        String str1 = "hello";
        String str2 = "abcde";

        System.out.println("Reversed: " + reverse(str1));  // Output: olleh
        System.out.println("Reversed: " + reverse(str2));  // Output: edcba
    }
}
