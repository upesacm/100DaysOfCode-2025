import java.util.Stack;

public class Q2 {
    static Stack<Integer> stack=new Stack<>();
    static Stack<Integer> minStack=new Stack<>();

    public static void push(int x) {
        stack.push(x);
        if (minStack.isEmpty() || x <= minStack.peek()) {
            minStack.push(x);
        }
    }

    public static int getMin() {
        return minStack.isEmpty() ? -1 : minStack.peek();
    }

    public static void main(String[] args) 
    {
        push(5);
        push(3);
        push(7);
        System.out.println(getMin());
    }
}
