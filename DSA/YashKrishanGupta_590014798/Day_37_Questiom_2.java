import java.util.*;
public class Day_37_Questiom_2 {
    //Solution 2
    static int evaluatePostfix(String postfix){
        Stack<Integer> values = new Stack<>();
        for(int i=0;i<postfix.length();i++) {
            char ch = postfix.charAt(i);
            if (ch >= 48 && ch <= 57) values.push(ch - 48);
            else {
                if (values.size() < 2) {
                    System.out.println("invalid postfix expression");
                    return -1;
                }
                int v2 = values.pop();
                int v1 = values.pop();
                switch (ch) {
                    case '+':
                        values.push(v1 + v2);
                        break;
                    case '-':
                        values.push(v1 - v2);
                        break;
                    case '*':
                        values.push(v1 * v2);
                        break;
                    case '/':
                        if (v2 == 0) {
                            System.out.println("division by zero");
                            return -1;
                        }
                        values.push(v1 / v2);
                        break;
                    case '%':
                        if (v2 == 0) {
                            System.out.println("modulus by zero");
                            return -1;
                        }
                        values.push(v1 % v2);
                        break;
                    default:
                        System.out.println("invalid operator: " + ch);
                        return -1;
                }
            }
        }
        if(values.size()>1){
            System.out.println("invalid postfix expression");
            return -1;
        }
        return values.peek();
    }
  
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Postfix Expression : ");
        String postfix = sc.next();
        int ans = evaluatePostfix(postfix);
        System.out.println(ans);
    }
}
