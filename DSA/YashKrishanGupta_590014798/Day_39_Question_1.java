import java.util.Stack;
public class Day_39_Question_1 {
    static void reverseStack(Stack<Integer> st){
        if (st.isEmpty()) return;
        int x = st.pop();
        reverseStack(st);
        insertAtBottom(st,x);
    }

    private static void insertAtBottom(Stack<Integer> st,int n){
        if(st.isEmpty()){
            st.push(n);
            return;
        }
        int x = st.pop();
        insertAtBottom(st,n);
        st.push(x);
    }

    public static void main(String[] args) {
        Stack<Integer> st = new Stack<>();
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);
        System.out.println("Before reversing : "+st);
        reverseStack(st);
        System.out.println("After reversing : "+st);
    }
}
