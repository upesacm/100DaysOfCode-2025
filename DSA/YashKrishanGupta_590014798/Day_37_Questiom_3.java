import java.util.Stack;
public class Day_37_Questiom_3 {
    //Solution 3
    static void deleteMiddleOfStack(Stack<Integer> st){
        if(st.isEmpty()) return;
        int middle = st.size()/2;
        deleteMiddle(st,middle,0);
    }
    private static void deleteMiddle(Stack<Integer> st,int middle,int idx){
        if(idx == middle){
            st.pop();
            return;
        }
        int x = st.pop();
        deleteMiddle(st,middle,idx+1);
        st.push(x);
    }

    public static void main(String[] args) {
        Stack<Integer> st  = new Stack<>();
        st.push(3);
        st.push(1);
        st.push(4);
        st.push(5);
        st.push(2);
        System.out.println("Before Deleting : "+st);
        deleteMiddleOfStack(st);
        System.out.println("After Deleting : "+st);
    }
}
