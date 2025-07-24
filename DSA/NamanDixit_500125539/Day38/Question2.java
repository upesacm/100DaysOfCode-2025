
import java.util.*;

public class Question2 {

    private Deque<Integer> stack;
    private Deque<Integer> minStack; // Tracks current minimums

    public Question2() {
        stack = new ArrayDeque<>();
        minStack = new ArrayDeque<>();
    }

    // Pushes an element onto the stack
    public void push(int val) {
        stack.push(val);
        if (minStack.isEmpty() || val <= minStack.peek()) {
            minStack.push(val);
        }
    }

    // Removes the top element
    public void pop() {
        if (stack.isEmpty()) {
            System.out.println("Stack is empty. Cannot pop.");
            return;
        }

        int top = stack.pop();
        if (top == minStack.peek()) {
            minStack.pop();
        }
    }

    // Returns the top element
    public int top() {
        if (stack.isEmpty()) {
            System.out.println("Stack is empty.");
            return -1;
        }
        return stack.peek();
    }

    // Retrieves the current minimum
    public int getMin() {
        if (minStack.isEmpty()) {
            System.out.println("Stack is empty. No minimum.");
            return -1;
        }
        return minStack.peek();
    }

    public static void main(String[] args) {
        Question2 minStack = new Question2();
        Scanner sc = new Scanner(System.in);

        System.out.println("Commands: push <val>, pop, top, getMin, exit");

        while (true) {
            String cmd = sc.next();

            if (cmd.equalsIgnoreCase("push")) {
                int val = sc.nextInt();
                minStack.push(val);
                System.out.println(val + " pushed.");
            } else if (cmd.equalsIgnoreCase("pop")) {
                minStack.pop();
            } else if (cmd.equalsIgnoreCase("top")) {
                int top = minStack.top();
                if (top != -1) {
                    System.out.println("Top: " + top);
                }
            } else if (cmd.equalsIgnoreCase("getMin")) {
                int min = minStack.getMin();
                if (min != -1) {
                    System.out.println("Current Min: " + min);
                }
            } else if (cmd.equalsIgnoreCase("exit")) {
                break;
            } else {
                System.out.println("Invalid command.");
            }
        }

        sc.close();
    }
}
