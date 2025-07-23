import java.util.*;
public class Day_36_Question_1 {
    // Solution 1
    public static String reverseString(String s){
        Stack<Character> st = new Stack<>();
        for(int i=0;i<s.length();i++){
            st.push(s.charAt(i));
        }
        StringBuilder rev = new StringBuilder();
        while(!st.isEmpty()){
            rev.append(st.pop());
        }
        return rev.toString();
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the String : ");
        String s = sc.nextLine();
        String rev = reverseString(s);
        System.out.println(rev);
    }
}
