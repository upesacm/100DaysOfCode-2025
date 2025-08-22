import java.util.*;

public class Q1 {

    public static Queue<Integer> insertAtRear(Queue<Integer> queue, int element) {
        queue.offer(element); 
        return queue;
    }

    // Demo
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>(List.of(10, 20, 30));
        insertAtRear(queue, 40);
        System.out.println(queue); 
    }
}
