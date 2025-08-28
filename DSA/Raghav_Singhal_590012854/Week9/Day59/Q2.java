import java.util.*;

class Q2 {
    private PriorityQueue<Integer> maxHeap;

    public Q2() {
        maxHeap = new PriorityQueue<>(Collections.reverseOrder());
    }

    public void insert(int val) {
        maxHeap.add(val);
    }

    public int extractMax() {
        if (maxHeap.isEmpty()) {
            System.out.println("Heap is empty!");
            return Integer.MIN_VALUE;
        }
        return maxHeap.poll(); 
    }

    public int peekMax() {
        if (maxHeap.isEmpty()) {
            System.out.println("Heap is empty!");
            return Integer.MIN_VALUE;
        }
        return maxHeap.peek();
    }

    public void printHeap() {
        System.out.println(maxHeap);
    }

    public static void main(String[] args) {
        Q2 maxHeap = new Q2();

        maxHeap.insert(5);
        maxHeap.insert(1);
        maxHeap.insert(10);
        System.out.println("Extracted Max: " + maxHeap.extractMax()); 

        maxHeap.insert(3);
        maxHeap.insert(7);
        maxHeap.insert(2);
        maxHeap.insert(9);
        System.out.println("Extracted Max: " + maxHeap.extractMax()); 
        System.out.println("Extracted Max: " + maxHeap.extractMax()); 
    }
}
