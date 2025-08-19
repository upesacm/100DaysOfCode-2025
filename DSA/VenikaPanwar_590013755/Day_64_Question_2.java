import java.util.*;

class Item {
    int weight, value;
    Item(int w, int v) { weight = w; value = v; }
}

public class FractionalKnapsack {
    public static double getMaxValue(Item[] items, int capacity) {
        Arrays.sort(items, (a, b) -> Double.compare((double)b.value / b.weight, (double)a.value / a.weight));

        double totalValue = 0.0;
        int remaining = capacity;

        for (Item item : items) {
            if (remaining >= item.weight) {
                totalValue += item.value;
                remaining -= item.weight;
            } else {
                totalValue += (double)item.value * remaining / item.weight;
                break;
            }
        }
        return totalValue;
    }

    public static void main(String[] args) {
        Item[] items1 = { new Item(10, 60), new Item(20, 100), new Item(30, 120) };
        System.out.println(getMaxValue(items1, 50)); // 240.0

        Item[] items2 = { new Item(5, 50), new Item(10, 60) };
        System.out.println(getMaxValue(items2, 10)); // 80.0
    }
}
