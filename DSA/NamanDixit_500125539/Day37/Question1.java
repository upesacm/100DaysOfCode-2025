import java.util.Scanner;
import java.util.Stack;

public class Question1 {

    static Stack<Integer> sortStack(Stack<Integer> input) {
        Stack<Integer> tempStack = new Stack<Integer>();
        while (!input.isEmpty()) {
            int temp = input.pop();
            while (!tempStack.isEmpty() && tempStack.peek() > temp) {
                input.push(tempStack.pop());
            }
            tempStack.push(temp);
        }
        return tempStack;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Stack<Integer> input = new Stack<>();

        System.out.print("Enter number of elements in the stack: ");
        int n = scanner.nextInt();

        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            input.push(scanner.nextInt());
        }
        System.out.println(sortStack(input));
    }
}
