import java.util.*;

public class Question2{

    private PriorityQueue<Integer> maxHeap; // Lower half
    private PriorityQueue<Integer> minHeap; // Upper half

    public Question2() {
        // Max-heap for lower half (largest element at top)
        maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        // Min-heap for upper half (smallest element at top)
        minHeap = new PriorityQueue<>();
    }

    public void addNumber(int num) {
        // Add to appropriate heap
        if (maxHeap.isEmpty() || num <= maxHeap.peek()) {
            maxHeap.offer(num);
        } else {
            minHeap.offer(num);
        }

        // Balance heaps so their sizes differ at most by 1
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.offer(maxHeap.poll());
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.offer(minHeap.poll());
        }
    }

    public double getMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.peek() + minHeap.peek()) / 2.0;
        } else {
            return maxHeap.peek();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Question2 tracker = new Question2();

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.println("Running Medians:");
        for (int num : arr) {
            tracker.addNumber(num);
            double median = tracker.getMedian();
            // Print without trailing .0 if integer
            if (median == (int) median) {
                System.out.print((int) median + " ");
            } else {
                System.out.print(median + " ");
            }
        }
        sc.close();
    }
}
