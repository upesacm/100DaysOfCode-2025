import java.util.*;
public class Day_36_Question_3 {
    // Solution 3
    public static void insertAtBottom(Stack<Integer> st,int n){
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
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the integer to insert at bottom of stack : ");
        int n = sc.nextInt();
        System.out.println("Before insertion Stack : " + st);
        insertAtBottom(st,n);
        System.out.println("After insertion Stack : " + st);
    }
}
