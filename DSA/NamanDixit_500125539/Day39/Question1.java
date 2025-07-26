import java.util.Scanner;
import java.util.Stack;

public class Question1{

    // Insert an element at the bottom of the stack using recursion
    public static void insertAtBottom(Stack<Integer> s, int item) {
        if (s.isEmpty()) {
            s.push(item);
            return;
        }

        int top = s.pop();
        insertAtBottom(s, item);
        s.push(top);
    }

    // Reverse the stack using recursion
    public static void reverseStack(Stack<Integer> s) {
        if (s.isEmpty()) {
            return;
        }

        int item = s.pop();
        reverseStack(s);
        insertAtBottom(s, item);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Stack<Integer> s = new Stack<>();

        System.out.print("Enter the number of elements in the stack: ");
        int n = scanner.nextInt();

        System.out.println("Enter " + n + " elements (from bottom to top):");
        for (int i = 0; i < n; i++) {
            s.push(scanner.nextInt());
        }
        // Print reversed stack (top to bottom)
        System.out.print("Reversed stack is: ");
        System.out.println(s);

        scanner.close();
    }
}
