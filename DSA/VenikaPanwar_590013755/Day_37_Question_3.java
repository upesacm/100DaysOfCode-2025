import java.util.Scanner;
import java.util.Stack;

public class Day_37_Question_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<Integer> stack = new Stack<>();

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        System.out.println("Enter elements (top to bottom):");
        for (int i = 0; i < n; i++) {
            stack.push(sc.nextInt());
        }

        deleteMiddle(stack, 0, n);

        System.out.println("Stack after deleting middle element (top to bottom):");
        while (!stack.isEmpty()) {
            System.out.print(stack.pop() + " ");
        }
    }

    static void deleteMiddle(Stack<Integer> stack, int current, int size) {
        if (stack.isEmpty() || current == size / 2) {
            stack.pop();
            return;
        }

        int temp = stack.pop();
        deleteMiddle(stack, current + 1, size);
        stack.push(temp);
    }
}
