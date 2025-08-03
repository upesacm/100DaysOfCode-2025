import java.util.Stack;

public class Q2 {

    public static String decodeString(String s) {
        Stack<Integer> countStack = new Stack<>();
        Stack<StringBuilder> stringStack = new Stack<>();
        StringBuilder currentString = new StringBuilder();
        int k = 0;

        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                countStack.push(k);     
                stringStack.push(currentString);
                k = 0;
                currentString = new StringBuilder();
            } else if (c == ']') {
                int count = countStack.pop(); 
                StringBuilder decoded = stringStack.pop();
                while (count-- > 0) {
                    decoded.append(currentString);
                }
                currentString = decoded;
            } else {
                currentString.append(c);
            }
        }

        return currentString.toString();
    }

    public static void main(String[] args) {
        System.out.println(decodeString("3[a]2[bc]"));
        System.out.println(decodeString("2[abc]3[cd]ef"));
        System.out.println(decodeString("3[a2[c]]")); 
    }
}