import java.util.Scanner;
import java.util.Stack;

public class Question3 {

    public Stack<Integer> insertAtBottom(Stack<Integer> st, int x) {
        Stack<Integer> s = new Stack<>();

        // Step 1: Move all elements from original stack to temp stack
        while (!st.isEmpty()) {
            s.push(st.pop());
        }

        // Step 2: Push the new element (x) to the now-empty original stack
        st.push(x);

        // Step 3: Push all elements back from temp stack to original stack
        while (!s.isEmpty()) {
            st.push(s.pop());
        }

        // Final stack has x at the bottom
        return st;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<Integer> stack = new Stack<>();

        System.out.print("Enter number of elements in stack: ");
        int n = sc.nextInt();

        System.out.println("Enter elements (top to bottom):");
        for (int i = 0; i < n; i++) {
            stack.push(sc.nextInt());
        }

        System.out.print("Enter element to insert at bottom: ");
        int x = sc.nextInt();

        Question3 obj = new Question3();
        Stack<Integer> result = obj.insertAtBottom(stack, x);

        while (!result.isEmpty()) {
            System.out.print(result.pop() + " ");
        }
    }
}
