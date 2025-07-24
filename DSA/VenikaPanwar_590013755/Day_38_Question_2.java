import java.util.Scanner;
import java.util.Stack;

class MinStack {
    Stack<Integer> stack = new Stack<>();
    Stack<Integer> minStack = new Stack<>();

    public void push(int x) {
        stack.push(x);
        if (minStack.isEmpty() || x <= minStack.peek())
            minStack.push(x);
    }

    public void pop() {
        if (stack.isEmpty()) return;
        int popped = stack.pop();
        if (popped == minStack.peek()) {
            minStack.pop();
        }
    }

    public int top() {
        return stack.isEmpty() ? -1 : stack.peek();
    }

    public int getMin() {
        return minStack.isEmpty() ? -1 : minStack.peek();
    }
}

public class MinStackTest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        MinStack ms = new MinStack();

        ms.push(8);
        ms.push(2);
        ms.push(6);
        ms.pop();
        System.out.println("Minimum: " + ms.getMin());  // Output: 2
    }
}
