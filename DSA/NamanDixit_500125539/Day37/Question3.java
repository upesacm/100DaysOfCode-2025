import java.util.Scanner;
import java.util.Stack;

public class Question3 {

    // Recursive helper function
    public static void deleteMidHelper(Stack<Integer> st, int count, int pos) {
        if (st.isEmpty()) return;

        int top = st.pop();

        if (count == pos) {
            return; // Skip pushing the middle element back
        }

        deleteMidHelper(st, count + 1, pos);
        st.push(top);
    }

    // Main function to delete middle element
    public static void deleteMiddle(Stack<Integer> st, int size) {
        int pos = (int) Math.ceil((size + 1) / 2.0);
        deleteMidHelper(st, 1, pos);
    }

    // Main method to test
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<Integer> stack = new Stack<>();

        System.out.print("Enter the number of elements in the stack: ");
        int n = sc.nextInt();

        System.out.println("Enter " + n + " elements (top element first):");
        for (int i = 0; i < n; i++) {
            stack.push(sc.nextInt());
        }

        System.out.println("Original Stack: " + stack);

        deleteMiddle(stack, n);

        System.out.println("Stack after deleting middle element: " + stack);
    }
}
