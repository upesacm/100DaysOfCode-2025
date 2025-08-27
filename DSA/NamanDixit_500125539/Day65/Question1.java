import java.util.*;

public class Question1 {

    // Function to compute minimum coins and also track which coins are used
    public static List<Integer> minimumCoins(int[] coins, int amount) {
        int max = amount + 1;
        int[] dp = new int[amount + 1];  // dp[i] = min coins needed for sum i
        int[] lastCoin = new int[amount + 1];  // last coin used to make amount i

        Arrays.fill(dp, max);
        Arrays.fill(lastCoin, -1);

        dp[0] = 0;

        // Fill DP table
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i && dp[i - coin] + 1 < dp[i]) {
                    dp[i] = dp[i - coin] + 1;
                    lastCoin[i] = coin;
                }
            }
        }

        // If amount cannot be formed
        if (dp[amount] > amount) {
            return new ArrayList<>(); // return empty list
        }

        // Reconstruct the coins used
        List<Integer> result = new ArrayList<>();
        int cur = amount;
        while (cur > 0 && lastCoin[cur] != -1) {
            result.add(lastCoin[cur]);
            cur -= lastCoin[cur];
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read coin denominations
        System.out.print("Enter number of coin types: ");
        int n = sc.nextInt();

        int[] coins = new int[n];
        System.out.println("Enter the coin denominations:");
        for (int i = 0; i < n; i++) {
            coins[i] = sc.nextInt();
        }

        // Read target amount
        System.out.print("Enter the target amount: ");
        int amount = sc.nextInt();

        // Compute result
        List<Integer> coinsUsed = minimumCoins(coins, amount);

        if (coinsUsed.isEmpty()) {
            System.out.println("It's not possible to make up the amount with the given coins.");
        } else {
            System.out.println("Minimum number of coins: " + coinsUsed.size());
            for (int i = 0; i < coinsUsed.size(); i++) {
                if (i > 0) System.out.print("+");
                System.out.print(coinsUsed.get(i));
            }
            System.out.println();
        }

        sc.close();
    }
}
