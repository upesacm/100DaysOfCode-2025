import java.util.*;

public class Day_39_Question_2 {
    public static int[] calculateSpan(int[] prices) {
        int n = prices.length;
        int[] span = new int[n];
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && prices[stack.peek()] <= prices[i]) {
                stack.pop();
            }

            span[i] = stack.isEmpty() ? (i + 1) : (i - stack.peek());
            stack.push(i);
        }

        return span;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of days: ");
        int n = sc.nextInt();
        int[] prices = new int[n];
        System.out.println("Enter daily stock prices:");
        for (int i = 0; i < n; i++) prices[i] = sc.nextInt();

        int[] span = calculateSpan(prices);
        System.out.println("Stock Spans:");
        for (int s : span) System.out.print(s + " ");
    }
}
