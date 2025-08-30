import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Q1 {

    public static void findMinimumCoins(int[] coins, int amount) {
        Arrays.sort(coins); 
        int n = coins.length;

        System.out.println("\nAvailable denominations: " + Arrays.toString(coins));
        System.out.println("Target Amount: " + amount);
        System.out.println("\nGreedy Selection Steps:");

        int count = 0;
        List<Integer> result = new ArrayList<>();

        for (int i = n - 1; i >= 0; i--) {
            while (amount >= coins[i]) {
                amount -= coins[i];
                result.add(coins[i]);
                count++;
                System.out.println("Selected coin: " + coins[i] + " | Remaining amount: " + amount);
            }
        }

        if (amount != 0) {
            System.out.println("\n⚠ Cannot make the target amount with given denominations!");
            return;
        }

        System.out.println("\nMinimum number of coins required: " + count);
        System.out.println("Coins used: " + result);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of denominations: ");
        int n = sc.nextInt();
        int[] coins = new int[n];
        System.out.println("Enter coin denominations: ");
        for (int i = 0; i < n; i++) {
            coins[i] = sc.nextInt();
        }

        System.out.print("Enter the target amount: ");
        int amount = sc.nextInt();

        findMinimumCoins(coins, amount);

        sc.close();
    }
}
