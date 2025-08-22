import java.util.*;

public class InsertAtRear {
    public static Queue<Integer> insertRear(Queue<Integer> queue, int element) {
        queue.add(element); // Add to the rear (tail)
        return queue;
    }

    public static void main(String[] args) {
        Queue<Integer> q = new LinkedList<>(Arrays.asList(1, 2));
        int toInsert = 3;

        Queue<Integer> result = insertRear(q, toInsert);
        System.out.println("Updated Queue: " + result);
    }
}
