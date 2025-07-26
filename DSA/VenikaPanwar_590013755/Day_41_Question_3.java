import java.util.Scanner;
import java.util.Stack;

public class Day_41_Question_3 {
    public static String removeKdigits(String num, int k) {
        Stack<Character> stack = new Stack<>();

        for (char digit : num.toCharArray()) {
            while (!stack.isEmpty() && k > 0 && stack.peek() > digit) {
                stack.pop();
                k--;
            }
            stack.push(digit);
        }

        // Remove extra digits if k > 0
        while (k-- > 0) stack.pop();

        // Build result
        StringBuilder result = new StringBuilder();
        for (char ch : stack) result.append(ch);

        // Remove leading zeros
        while (result.length() > 0 && result.charAt(0) == '0') result.deleteCharAt(0);

        return result.length() == 0 ? "0" : result.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number string: ");
        String num = sc.nextLine();
        System.out.print("Enter digits to remove (k): ");
        int k = sc.nextInt();

        String output = removeKdigits(num, k);
        System.out.println("Smallest possible number: " + output);
    }
}
