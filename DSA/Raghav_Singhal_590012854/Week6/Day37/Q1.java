import java.util.*;
public class Q1 {
    public static void sort(Stack<Integer> st) {
        Stack<Integer> newst = new Stack<>();
        if (st.isEmpty()) {
            return;
        }
        newst.push(st.pop());
        while(!st.isEmpty())
        {
            if(st.peek()<newst.peek())
            {
                int temp=st.pop();
                while(!newst.isEmpty() && temp<newst.peek())
                {
                    st.push(newst.pop());
                }
                newst.push(temp);
            }
            else
            {
                newst.push(st.pop());
            }
        }
        printStack(newst);
    }
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        stack.push(3);
        stack.push(1);
        stack.push(4);
        stack.push(2);
        
        sort(stack);
    }
    public static void printStack(Stack<Integer> stack) {
        System.out.print("[ ");
        for (int i = 0; i <stack.size(); i++) {
            System.out.print(stack.get(i) + ", ");
        }
        System.out.println("]");
    }
    
}
