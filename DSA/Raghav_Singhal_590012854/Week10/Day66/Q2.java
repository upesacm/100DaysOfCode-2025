import java.util.*;

public class Q2 {

    public static int maxProfit(int[] prices) {
        if (prices.length == 0) return 0;

        int buy_price = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.length; i++) {
            if (prices[i] < buy_price) {
                buy_price = prices[i];
            } else {
                int current_profit = prices[i] - buy_price;
                profit = Math.max(profit, current_profit);
            }
        }
        return profit;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of days: ");
        int n = sc.nextInt();

        int[] prices = new int[n];
        System.out.println("Enter stock prices for " + n + " days:");
        for (int i = 0; i < n; i++) {
            prices[i] = sc.nextInt();
        }
        sc.close();

        int result = maxProfit(prices);
        System.out.println("Maximum Profit: " + result);
    }
}
