import java.util.*;

public class Day_67_Question_2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of ropes: ");
        int n = scanner.nextInt();
        
        int[] ropes = new int[n];
        System.out.println("Enter the rope lengths:");
        
        for (int i = 0; i < n; i++) {
            ropes[i] = scanner.nextInt();
        }
        
        int minimumCost = calculateMinimumCost(ropes);
        System.out.println("Minimum cost to connect all ropes: " + minimumCost);
        
        scanner.close();
    }
    
    public static int calculateMinimumCost(int[] ropes) {
        // Edge case: if less than 2 ropes, no connection needed
        if (ropes.length < 2) {
            return 0;
        }
        
        // Create a min-heap using PriorityQueue
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        
        // Add all rope lengths to the heap
        for (int rope : ropes) {
            minHeap.offer(rope);
        }
        
        int totalCost = 0;
        
        // Keep connecting ropes until only one remains
        while (minHeap.size() > 1) {
            // Extract two shortest ropes
            int first = minHeap.poll();
            int second = minHeap.poll();
            
            // Calculate cost of connecting these two ropes
            int currentCost = first + second;
            totalCost += currentCost;
            
            // Add the combined rope back to heap
            minHeap.offer(currentCost);
        }
        
        return totalCost;
    }
    
    // Alternative approach using ArrayList and manual sorting
    public static int calculateMinimumCostAlternative(int[] ropes) {
        if (ropes.length < 2) return 0;
        
        List<Integer> ropeList = new ArrayList<>();
        for (int rope : ropes) {
            ropeList.add(rope);
        }
        
        int totalCost = 0;
        
        while (ropeList.size() > 1) {
            Collections.sort(ropeList);
            
            int first = ropeList.remove(0);
            int second = ropeList.remove(0);
            
            int cost = first + second;
            totalCost += cost;
            
            ropeList.add(cost);
        }
        
        return totalCost;
    }
}
