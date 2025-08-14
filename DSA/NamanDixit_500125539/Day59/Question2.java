import java.util.*;

public class Question2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Max-Heap using PriorityQueue with reverse order comparator
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

        System.out.print("Enter number of operations: ");
        int n = sc.nextInt();
        sc.nextLine(); // consume newline

        for (int i = 0; i < n; i++) {
            System.out.print("Enter operation (insert X / extractMax): ");
            String input = sc.nextLine().trim();

            if (input.startsWith("insert")) {
                int value = Integer.parseInt(input.split(" ")[1]);
                maxHeap.add(value);
            } 
            else if (input.equalsIgnoreCase("extractMax")) {
                if (!maxHeap.isEmpty()) {
                    System.out.println("Extracted Max: " + maxHeap.poll());
                } else {
                    System.out.println("Heap is empty!");
                }
            } 
            else {
                System.out.println("Invalid operation!");
            }
        }

        sc.close();
    }
}
