import java.util.*;
public class Day_36_Question_2 {
    // Solution 2
    public static boolean isBalancedParentheses(String s){
        Stack<Character> st = new Stack<>();
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(ch=='(' || ch == '[' || ch == '{') st.push(ch);
            else if(ch == ')' || ch == ']' || ch == '}') {
                if(st.isEmpty()) return false;
                char top = st.peek();
                if((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{')) st.pop();
                else return false;
            }
        }
        return st.isEmpty();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the String (only (,),[,],{,} ) :");
        String s = sc.nextLine();
        if(isBalancedParentheses(s)) System.out.println("Balanced");
        else System.out.println("Not Balanced");
    }
}
