import java.util.*;
public class Day_38_Question_3 {
    static boolean isRedundantBrackets(String exp){
        Stack<Character> st = new Stack<>();
        for(int i=0;i<exp.length();i++){
            char ch = exp.charAt(i);
            boolean haveOperator = false;
            if(ch != ')') st.push(ch);
            else{
                while(!st.isEmpty() && st.peek() != ')'){
                    char top = st.pop();
                    if(top == '+' || top == '*' || top == '-' || top == '/') haveOperator = true;
                }

                if(!st.isEmpty()) st.pop();

                if(!haveOperator) return true;
            }
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Expression : ");
        String exp = sc.next();
        if(isRedundantBrackets(exp)) System.out.println("Yes");
        else System.out.println("No");
    }
}
