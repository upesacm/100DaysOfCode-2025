import java.util.Scanner;
import java.util.Stack;

public class Day_37_Question_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<Integer> input = new Stack<>();

        System.out.print("Enter number of elements in stack: ");
        int n = sc.nextInt();
        System.out.println("Enter elements (top to bottom):");
        for (int i = 0; i < n; i++) {
            input.push(sc.nextInt());
        }

        Stack<Integer> sorted = sortStack(input);

        System.out.println("Sorted Stack (top to bottom):");
        while (!sorted.isEmpty()) {
            System.out.print(sorted.pop() + " ");
        }
    }

    static Stack<Integer> sortStack(Stack<Integer> input) {
        Stack<Integer> tempStack = new Stack<>();

        while (!input.isEmpty()) {
            int curr = input.pop();

            while (!tempStack.isEmpty() && tempStack.peek() > curr) {
                input.push(tempStack.pop());
            }

            tempStack.push(curr);
        }

        return tempStack;
    }
}
