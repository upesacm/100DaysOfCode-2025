import java.util.Stack;

public class Q3 {

    public String removeKdigits(String num, int k) {
        Stack<Character> stack = new Stack<>();

        for (char digit : num.toCharArray()) {
            while (!stack.isEmpty() && k > 0 && stack.peek() > digit) {
                stack.pop();
                k--;
            }
            stack.push(digit);
        }

        while (k > 0 && !stack.isEmpty()) {
            stack.pop();
            k--;
        }

        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }
        sb.reverse();

        int i = 0;
        while (i < sb.length() && sb.charAt(i) == '0') {
            i++;
        }

        String result = sb.substring(i);

        if (result.isEmpty()) {
            return "0";
        }

        return result;
    }

    public static void main(String[] args) {
        RemoveKDigits remover = new RemoveKDigits();

        String num1 = "1432219";
        int k1 = 3;
        System.out.println("Input: num = \"" + num1 + "\", k = " + k1 + ", Output: \"" + remover.removeKdigits(num1, k1) + "\"");

        String num2 = "10200";
        int k2 = 1;
        System.out.println("Input: num = \"" + num2 + "\", k = " + k2 + ", Output: \"" + remover.removeKdigits(num2, k2) + "\"");

        String num3 = "10";
        int k3 = 2;
        System.out.println("Input: num = \"" + num3 + "\", k = " + k3 + ", Output: \"" + remover.removeKdigits(num3, k3) + "\"");

        String num4 = "12345";
        int k4 = 2;
        System.out.println("Input: num = \"" + num4 + "\", k = " + k4 + ", Output: \"" + remover.removeKdigits(num4, k4) + "\"");

        String num5 = "9876543210";
        int k5 = 5;
        System.out.println("Input: num = \"" + num5 + "\", k = " + k5 + ", Output: \"" + remover.removeKdigits(num5, k5) + "\"");
    }
}
