import java.util.Scanner;
import java.util.Stack;

public class Day_39_Question_1 {

    // Insert element at bottom using recursion
    static void insertAtBottom(Stack<Integer> stack, int x) {
        if (stack.isEmpty()) {
            stack.push(x);
            return;
        }
        int top = stack.pop();
        insertAtBottom(stack, x);
        stack.push(top);
    }

    // Reverse the stack recursively
    static void reverseStack(Stack<Integer> stack) {
        if (stack.isEmpty()) return;
        int top = stack.pop();
        reverseStack(stack);
        insertAtBottom(stack, top);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<Integer> stack = new Stack<>();

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        System.out.println("Enter elements (top to bottom):");
        for (int i = 0; i < n; i++) stack.push(sc.nextInt());

        reverseStack(stack);

        System.out.println("Reversed Stack:");
        while (!stack.isEmpty()) System.out.print(stack.pop() + " ");
    }
}
