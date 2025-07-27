import java.util.*;

public class Question2 {
    public String decodeString(String s) {
        Stack<Integer> countStack = new Stack<>();
        Stack<StringBuilder> stringStack = new Stack<>();
        StringBuilder current = new StringBuilder();
        int k = 0;

        for (char ch : s.toCharArray()) {
            if (Character.isDigit(ch)) {
                k = k * 10 + (ch - '0');
            } else if (ch == '[') {
                countStack.push(k);
                stringStack.push(current);
                current = new StringBuilder();
                k = 0;
            } else if (ch == ']') {
                StringBuilder decoded = stringStack.pop();
                int count = countStack.pop();
                for (int i = 0; i < count; i++) {
                    decoded.append(current);
                }
                current = decoded;
            } else {
                current.append(ch);
            }
        }

        return current.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        Question2 obj = new Question2();
        System.out.println(obj.decodeString(input));
    }
}
