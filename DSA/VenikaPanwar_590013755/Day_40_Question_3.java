import java.util.Scanner;
import java.util.Stack;

class MaxStack {
    Stack<Integer> main = new Stack<>();
    Stack<Integer> maxStack = new Stack<>();

    public void push(int x) {
        main.push(x);
        if (maxStack.isEmpty() || x >= maxStack.peek())
            maxStack.push(x);
    }

    public void pop() {
        if (!main.isEmpty()) {
            int top = main.pop();
            if (top == maxStack.peek()) {
                maxStack.pop();
            }
        }
    }

    public int top() {
        return main.isEmpty() ? -1 : main.peek();
    }

    public int getMax() {
        return maxStack.isEmpty() ? -1 : maxStack.peek();
    }
}

public class MaxStackTest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        MaxStack ms = new MaxStack();

        ms.push(3);
        ms.push(5);
        ms.push(2);
        System.out.println("Current Max: " + ms.getMax()); // 5

        ms.pop();
        System.out.println("Current Max: " + ms.getMax()); // 5

        ms.pop();
        System.out.println("Current Max: " + ms.getMax()); // 3
    }
}
