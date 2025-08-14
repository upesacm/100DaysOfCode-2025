import java.util.*;
public class Q2 {
    public static void main(String[] args) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        maxHeap.add(5);
        maxHeap.add(1);
        maxHeap.add(10);
        System.out.println(maxHeap.poll());
    }
}
