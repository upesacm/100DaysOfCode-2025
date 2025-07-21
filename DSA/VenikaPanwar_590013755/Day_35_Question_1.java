import java.util.Scanner;
import java.util.Stack;

public class Day_36_Question_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string to reverse: ");
        String input = sc.nextLine();

        Stack<Character> stack = new Stack<>();

        // Push characters into the stack
        for (char ch : input.toCharArray()) {
            stack.push(ch);
        }

        // Pop to reverse
        StringBuilder reversed = new StringBuilder();
        while (!stack.isEmpty()) {
            reversed.append(stack.pop());
        }

        System.out.println("Reversed: " + reversed);
    }
}
