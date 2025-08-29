import java.util.*;

class Item {
    int value, weight;
    Item(int v, int w) {
        value = v;
        weight = w;
    }
}

public class Q2 {
    public static void main(String[] args) {
        int[] values = {60, 100, 120};
        int[] weights = {10, 20, 30};
        int capacity = 50;

        double maxValue = getMaxValue(values, weights, capacity);
        System.out.println("Maximum value in Knapsack = " + maxValue);
    }

    public static double getMaxValue(int[] values, int[] weights, int capacity) {
        int n = values.length;
        Item[] items = new Item[n];

        for (int i = 0; i < n; i++) {
            items[i] = new Item(values[i], weights[i]);
        }

        Arrays.sort(items, (a, b) -> 
            Double.compare((double)b.value / b.weight, (double)a.value / a.weight)
        );

        double totalValue = 0.0;
        int remainingCapacity = capacity;

        for (Item item : items) {
            if (item.weight <= remainingCapacity) {
                totalValue += item.value;
                remainingCapacity -= item.weight;
            } else {
                totalValue += (double)item.value * ((double)remainingCapacity / item.weight);
                break; 
            }
        }

        return totalValue;
    }
}
