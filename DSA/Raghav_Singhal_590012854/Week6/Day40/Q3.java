import java.util.Stack;

public class Q3 {
    static Stack<Integer> stack = new Stack<>();
    static Stack<Integer> maxStack = new Stack<>();

    public static void push(int x) {
        stack.push(x);
        if (maxStack.isEmpty() || x >= maxStack.peek()) {
            maxStack.push(x);
        }
    }

    public static int pop() {
        if (stack.isEmpty()) return -1;
        int popped = stack.pop();
        if (popped == maxStack.peek()) maxStack.pop();
        return popped;
    }

    public static int top() {
        return stack.isEmpty() ? -1 : stack.peek();
    }

    public static int getMax() {
        return maxStack.isEmpty() ? -1 : maxStack.peek();
    }

    public static boolean isEmpty() {
        return stack.isEmpty();
    }

    public static void main(String[] args) {
        push(3);
        push(5);
        push(2);

        System.out.println("Max: " +getMax());
        System.out.println("Pop: " + pop());   
        System.out.println("Max: " + getMax());  
    }
}
