import java.util.*;

public class ConnectRopes {
    public static int minCost(int[] ropes) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int rope : ropes) minHeap.add(rope);

        int totalCost = 0;
        while (minHeap.size() > 1) {
            int first = minHeap.poll();
            int second = minHeap.poll();
            int cost = first + second;
            totalCost += cost;
            minHeap.add(cost);
        }
        return totalCost;
    }

    public static void main(String[] args) {
        System.out.println(minCost(new int[]{4, 3, 2, 6}));   // 29
        System.out.println(minCost(new int[]{1, 2, 3, 4, 5})); // 33
    }
}
