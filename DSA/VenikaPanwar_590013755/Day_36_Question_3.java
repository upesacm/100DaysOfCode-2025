import java.util.Scanner;
import java.util.Stack;

public class Day_36_Question_3 {
    public static void insertAtBottom(Stack<Integer> stack, int x) {
        if (stack.isEmpty()) {
            stack.push(x);
            return;
        }

        int temp = stack.pop();
        insertAtBottom(stack, x);
        stack.push(temp);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<Integer> stack = new Stack<>();

        System.out.print("Enter number of elements in stack: ");
        int n = sc.nextInt();
        System.out.println("Enter " + n + " stack elements (top to bottom):");
        for (int i = 0; i < n; i++) {
            stack.push(sc.nextInt());
        }

        System.out.print("Enter element to insert at bottom: ");
        int x = sc.nextInt();

        insertAtBottom(stack, x);

        System.out.println("Stack after insertion at bottom:");
        while (!stack.isEmpty()) {
            System.out.print(stack.pop() + " ");
        }
    }
}
