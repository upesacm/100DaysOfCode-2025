import java.util.*;

public class MinimumCoins {
    public static int minCoins(int[] coins, int amount) {
        Arrays.sort(coins);
        int count = 0;
        List<Integer> used = new ArrayList<>();

        for (int i = coins.length - 1; i >= 0 && amount > 0; i--) {
            while (amount >= coins[i]) {
                amount -= coins[i];
                count++;
                used.add(coins[i]);
            }
        }

        System.out.println("Coins used: " + used);
        return count;
    }

    public static void main(String[] args) {
        System.out.println("Result: " + minCoins(new int[]{1, 2, 5, 10}, 23)); 
        // 5 (10+10+2+1)

        System.out.println("Result: " + minCoins(new int[]{1, 5, 6, 9}, 11)); 
        // 2 (5+6)
    }
}
