import java.util.Arrays;
import java.util.Scanner;

class Item {
    int value, weight;
    
    // Constructor to initialize value and weight
    public Item(int value, int weight) {
        this.value = value;
        this.weight = weight;
    }
}

public class Question2 {
    
    // Function to solve the fractional knapsack problem
    public static double fractionalKnapsack(int capacity, Item[] items, int n) {
        // Sort items by value/weight ratio in descending order
        Arrays.sort(items, (a, b) -> Double.compare((double)b.value / b.weight, (double)a.value / a.weight));

        double totalValue = 0.0;
        int currentWeight = 0;

        for (int i = 0; i < n; i++) {
            // If adding the item won't exceed the capacity, add it fully
            if (currentWeight + items[i].weight <= capacity) {
                currentWeight += items[i].weight;
                totalValue += items[i].value;
            } 
            // Otherwise, add the fraction of the item that fits
            else {
                int remainingCapacity = capacity - currentWeight;
                totalValue += items[i].value * ((double) remainingCapacity / items[i].weight);
                break;
            }
        }
        
        return totalValue;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input for number of items
        System.out.print("Enter the number of items: ");
        int n = scanner.nextInt();

        Item[] items = new Item[n];

        // Input for values and weights
        System.out.println("Enter the values and weights of the items:");
        for (int i = 0; i < n; i++) {
            System.out.print("Value for item " + (i + 1) + ": ");
            int value = scanner.nextInt();
            System.out.print("Weight for item " + (i + 1) + ": ");
            int weight = scanner.nextInt();
            items[i] = new Item(value, weight);
        }

        // Input for knapsack capacity
        System.out.print("Enter the capacity of the knapsack: ");
        int capacity = scanner.nextInt();

        // Call the fractionalKnapsack function
        double maxProfit = fractionalKnapsack(capacity, items, n);

        // Output the result
        System.out.println("Maximum profit: " + maxProfit);

        scanner.close();
    }
}
