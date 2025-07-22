import java.util.*;

public class Q3 {
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);

        int size = stack.size();
        deleteMiddle(stack, 0, size);

        System.out.println("Stack after deleting middle: " + stack);
    }

    static void deleteMiddle(Stack<Integer> stack, int current, int size) {
        if (stack.isEmpty() || current == size / 2) {
            stack.pop();
            return;
        }

        int top = stack.pop();
        deleteMiddle(stack, current + 1, size);
        stack.push(top);
    }
}
