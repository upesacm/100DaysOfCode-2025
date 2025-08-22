import java.util.*;

public class MaxHeapUsingPQ {
    public static void main(String[] args) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

        maxHeap.add(5);
        maxHeap.add(1);
        maxHeap.add(10);
        System.out.println(maxHeap.poll()); // 10

        PriorityQueue<Integer> maxHeap2 = new PriorityQueue<>(Collections.reverseOrder());
        maxHeap2.add(3);
        maxHeap2.add(7);
        maxHeap2.add(2);
        maxHeap2.add(9);
        System.out.println(maxHeap2.poll()); // 9
        System.out.println(maxHeap2.poll()); // 7
    }
}
