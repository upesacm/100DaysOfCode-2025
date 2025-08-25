import java.util.*;

public class Day_68_Question_2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of ropes: ");
        int n = scanner.nextInt();
        
        int[] ropeLengths = new int[n];
        System.out.println("Enter the rope lengths:");
        
        for (int i = 0; i < n; i++) {
            ropeLengths[i] = scanner.nextInt();
        }
        
        int minimumCost = findMinimumConnectionCost(ropeLengths);
        System.out.println("Minimum cost to connect all ropes: " + minimumCost);
        
        // Demonstrate with step-by-step process
        demonstrateConnectionProcess(ropeLengths.clone());
        
        // Show examples
        demonstrateExamples();
        
        scanner.close();
    }
    
    /**
     * Calculates minimum cost to connect all ropes using min-heap greedy strategy
     * Always connects the two shortest ropes first to minimize cumulative cost
     */
    public static int findMinimumConnectionCost(int[] ropes) {
        // Edge case: less than 2 ropes means no connection needed
        if (ropes.length < 2) {
            return 0;
        }
        
        // Create min-heap using PriorityQueue for efficient minimum extraction
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        
        // Add all rope lengths to the min-heap
        for (int ropeLength : ropes) {
            minHeap.offer(ropeLength);
        }
        
        int totalConnectionCost = 0;
        
        // Continue until only one rope remains
        while (minHeap.size() > 1) {
            // Extract two shortest ropes from heap
            int firstShortest = minHeap.poll();
            int secondShortest = minHeap.poll();
            
            // Calculate cost of connecting these two ropes
            int connectionCost = firstShortest + secondShortest;
            totalConnectionCost += connectionCost;
            
            // Add the newly formed rope back to heap
            minHeap.offer(connectionCost);
        }
        
        return totalConnectionCost;
    }
    
    /**
     * Alternative implementation using ArrayList with manual sorting
     * Less efficient but demonstrates the concept clearly
     */
    public static int findMinimumCostAlternative(int[] ropes) {
        if (ropes.length < 2) return 0;
        
        List<Integer> ropeList = new ArrayList<>();
        for (int rope : ropes) {
            ropeList.add(rope);
        }
        
        int totalCost = 0;
        
        while (ropeList.size() > 1) {
            // Sort to find two shortest ropes
            Collections.sort(ropeList);
            
            // Remove and connect two shortest ropes
            int first = ropeList.remove(0);
            int second = ropeList.remove(0);
            
            int cost = first + second;
            totalCost += cost;
            
            // Add connected rope back to list
            ropeList.add(cost);
        }
        
        return totalCost;
    }
    
    /**
     * Demonstrates the step-by-step connection process
     */
    public static void demonstrateConnectionProcess(int[] ropes) {
        System.out.println("\n--- Connection Process ---");
        
        if (ropes.length < 2) {
            System.out.println("No connections needed for less than 2 ropes.");
            return;
        }
        
        PriorityQueue<Integer> heap = new PriorityQueue<>();
        for (int rope : ropes) {
            heap.offer(rope);
        }
        
        int step = 1;
        int totalCost = 0;
        
        while (heap.size() > 1) {
            int first = heap.poll();
            int second = heap.poll();
            int cost = first + second;
            totalCost += cost;
            
            System.out.println("Step " + step + ": Connect ropes of length " + 
                             first + " and " + second + " -> Cost: " + cost);
            
            heap.offer(cost);
            step++;
        }
        
        System.out.println("Total minimum cost: " + totalCost);
    }
    
    /**
     * Demonstrates the algorithm with provided examples
     */
    public static void demonstrateExamples() {
        System.out.println("\n--- Example Demonstrations ---");
        
        // Example 1: [4, 3, 2, 6] -> 29
        int[] example1 = {4, 3, 2, 6};
        int result1 = findMinimumConnectionCost(example1);
        System.out.println("Example 1: [4, 3, 2, 6] -> " + result1);
        
        // Example 2: [1, 2, 3, 4, 5] -> 33
        int[] example2 = {1, 2, 3, 4, 5};
        int result2 = findMinimumConnectionCost(example2);
        System.out.println("Example 2: [1, 2, 3, 4, 5] -> " + result2);
    }
}
