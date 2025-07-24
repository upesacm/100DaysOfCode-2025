import java.util.*;
public class Q1 {
    public static int[] greater(Stack<Integer> st) {
        int n = st.size();
        int[] result = new int[n];
        Stack<Integer> stack = new Stack<>(); 

        for (int i = n - 1; i >= 0; i--) 
        {
            while (!stack.isEmpty() && st.get(stack.peek()) <= st.get(i))
                stack.pop();

            result[i] = stack.isEmpty() ? -1 : st.get(stack.peek());
            stack.push(i);
        }

        return result;
    }
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        
        stack.push(4);
        stack.push(5);
        stack.push(2);
        stack.push(25);
        
        
        printStack(greater(stack));

    }
    public static void printStack(int[] arr) {
        System.out.print("[ ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + ", ");
        }
        System.out.println("]");
    }
    
}
