import java.util.*;

public class Question1 {
    static class Node {
        char data;
        int freq;

        Node(char d, int f) {
            data = d;
            freq = f;
        }
    }

    public String removeDuplicates(String s, int k) {
        Stack<Node> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (!stack.isEmpty() && stack.peek().data == c) {
                Node rv = stack.pop();
                rv.freq += 1;
                stack.push(rv);
            } else {
                stack.push(new Node(c, 1));
            }

            if (!stack.isEmpty() && stack.peek().freq == k) {
                stack.pop();
            }
        }

        StringBuilder builder = new StringBuilder();
        while (!stack.isEmpty()) {
            Node rv = stack.pop();
            int freq = rv.freq;
            while (freq-- > 0) {
                builder.append(rv.data);
            }
        }

        return builder.reverse().toString();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the string: ");
        String s = scanner.nextLine();

        System.out.print("Enter removal threshold: ");
        int k = scanner.nextInt();

        Question1 obj = new Question1();
        String result = obj.removeDuplicates(s, k);

        System.out.println(result);
    }
}
