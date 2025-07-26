import java.util.*;

public class Day_41_Question_2 {
    public static String decodeString(String s) {
        Stack<String> strStack = new Stack<>();
        Stack<Integer> countStack = new Stack<>();
        StringBuilder current = new StringBuilder();
        int k = 0;

        for (char ch : s.toCharArray()) {
            if (Character.isDigit(ch)) {
                k = k * 10 + (ch - '0');
            } else if (ch == '[') {
                countStack.push(k);
                strStack.push(current.toString());
                current = new StringBuilder();
                k = 0;
            } else if (ch == ']') {
                StringBuilder decoded = new StringBuilder(strStack.pop());
                int repeat = countStack.pop();
                decoded.append(current.toString().repeat(repeat));
                current = decoded;
            } else {
                current.append(ch);
            }
        }

        return current.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter encoded string: ");
        String input = sc.nextLine();

        String result = decodeString(input);
        System.out.println("Decoded string: " + result);
    }
}
