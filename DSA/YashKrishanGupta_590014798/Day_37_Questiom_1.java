import java.util.Stack;
public class Day_37_Questiom_1 {
    //Solution 1
    static void sortStack(Stack<Integer> st){
        Stack<Integer> helper = new Stack<>();
        while(!st.isEmpty()){
            int el = st.pop();
            while(!helper.isEmpty() && helper.peek() < el){
                st.push(helper.pop());
            }
            helper.push(el);
        }
        while(!helper.isEmpty()){
            st.push(helper.pop());
        }
    }
  
    public static void main(String[] args) {
        Stack<Integer> st  = new Stack<>();
        st.push(3);
        st.push(1);
        st.push(4);
        st.push(5);
        st.push(2);
        System.out.println("Before Sorting : "+st);
        sortStack(st);
        System.out.println("After Sorting : "+st);
    }
}
