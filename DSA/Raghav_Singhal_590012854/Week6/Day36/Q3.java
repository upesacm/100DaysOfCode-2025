import java.util.*;
public class Q3 {
    public static void insertAtBottom(Stack<Integer> stack, int x) {
        if (stack.isEmpty()) {
            stack.push(x);
            return;
        }

        int top = stack.pop();
        insertAtBottom(stack, x);
        stack.push(top);
    }
    public static void printStack(Stack<Integer> stack) {
        System.out.print("[ ");
        for (int i = 0; i <stack.size(); i++) {
            System.out.print(stack.get(i) + ", ");
        }
        System.out.println("]");
    }
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        
        insertAtBottom(stack, 0);
        printStack(stack);
    }
}
