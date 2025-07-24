import java.util.*;
public class Day_39_Question_2 {
    static int[] calculateSpan(int[] prices) {
        Stack<int[]> stack = new Stack<>();
        int[] span = new int[prices.length];

        for (int i = 0; i < prices.length; i++) {
            int currentPrice = prices[i];
            int currentSpan = 1;

            while (!stack.isEmpty() && stack.peek()[0] <= currentPrice) {
                currentSpan += stack.pop()[1];
            }

            stack.push(new int[]{currentPrice, currentSpan});
            span[i] = currentSpan;
        }

        return span;
    }

    public static void main(String[] args) {
        int[] prices = {100, 80, 60, 70, 60, 75, 85};
        int[] result = calculateSpan(prices);
        for(int el : result){
            System.out.print(el + " ");
        }
    }
}
