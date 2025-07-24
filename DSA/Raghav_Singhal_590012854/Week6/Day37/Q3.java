import java.util.*;
public class Q3 {
    static int mid=0;
    public static void sort(Stack<Integer> st,int cur) {
        int temp=st.pop();
        if(!st.isEmpty())
        {
            sort(st,cur+1);
        }
        if(mid==0) mid=cur/2;
        if(cur!=mid)
        st.push(temp);
    }
    public static void main(String[] args) {
        Stack<Integer> stack = new Stack<>();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        
        sort(stack,0);
        printStack(stack);

    }
    public static void printStack(Stack<Integer> stack) {
        System.out.print("[ ");
        for (int i = 0; i <stack.size(); i++) {
            System.out.print(stack.get(i) + ", ");
        }
        System.out.println("]");
    }
    
}
