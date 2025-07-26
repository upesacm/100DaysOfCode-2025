import java.util.*;
public class Q1 {
    public static Stack<Integer> rev(Stack<Integer> st) {
        if (!st.isEmpty()) {
            int temp = st.pop();
            rev(st);
            insertAtBottom(st, temp);
        }
        return st;
    }

    public static void insertAtBottom(Stack<Integer> st, int x) {
        if (st.isEmpty()) {
            st.push(x);
        } else {
            int temp = st.pop();
            insertAtBottom(st, x);
            st.push(temp);
        }
    }
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        printStack(stack);
        printStack(rev(stack));
    }
    public static void printStack(Stack<Integer> stack) {
        System.out.print("[ ");
        for (int i = 0; i <stack.size(); i++) {
            System.out.print(stack.get(i) + ", ");
        }
        System.out.println("]");
    }
    
}
