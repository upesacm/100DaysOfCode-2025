import java.util.*;

public class Question2 {
    private Stack<Integer> stack;        // holds indices of days
    private List<Integer> prices;        // holds the list of prices

    public Question2() {
        stack = new Stack<>();
        prices = new ArrayList<>();
    }

    // Process next price, return span (days including today)
    public int next(int price) {
        prices.add(price);
        int currentIndex = prices.size() - 1;

        // Pop all previous indices whose price <= current price
        while (!stack.isEmpty() && prices.get(stack.peek()) <= price) {
            stack.pop();
        }

        int prevGreaterIndex = stack.isEmpty() ? -1 : stack.peek();
        int span = currentIndex - prevGreaterIndex;

        // Push today's index onto stack
        stack.push(currentIndex);
        return span;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Question2 spanner = new Question2();

        System.out.print("Enter number of days: ");
        int n = sc.nextInt();

        System.out.println("Enter stock prices (one per day):");
        for (int i = 0; i < n; i++) {
            int price = sc.nextInt();
            int span = spanner.next(price);
            System.out.println("Day " + (i + 1) + " (Price: " + price + ") → Span: " + span);
        }

        sc.close();
    }
}
