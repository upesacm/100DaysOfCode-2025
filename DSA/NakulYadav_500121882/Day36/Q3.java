import java.util.Stack;

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
        for (int i = 0; i < stack.size(); i++) {
            System.out.print(stack.get(i) + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Stack<Integer> s1 = new Stack<>();
        s1.push(1);
        s1.push(2);
        s1.push(3);
        insertAtBottom(s1, 0);  
        printStack(s1);

        Stack<Integer> s2 = new Stack<>();
        s2.push(5);
        s2.push(6);
        insertAtBottom(s2, 9);  
        printStack(s2);
    }
}
