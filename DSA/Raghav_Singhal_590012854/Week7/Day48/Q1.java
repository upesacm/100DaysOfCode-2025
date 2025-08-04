import java.util.*;

public class Q1 {

    public static Queue<Integer> removeOccurrences(Queue<Integer> queue, int x) {
        int size = queue.size();

        for (int i = 0; i < size; i++) {
            int val = queue.poll();
            if (val != x) {
                queue.offer(val); 
            }
        }

        return queue;
    }
    public static void main(String[] args) {
        Queue<Integer> q1 = new LinkedList<>(List.of(1, 2, 3, 2, 4, 2));
        System.out.println("Original Queue: " + q1);
        Queue<Integer> updated = removeOccurrences(q1, 2);
        System.out.println("After Removing 2: " + updated); 
    }
}