import java.util.*;

public class RemoveOccurrences {
    public static Queue<Integer> removeAll(Queue<Integer> queue, int x) {
        int size = queue.size();

        for (int i = 0; i < size; i++) {
            int val = queue.remove();
            if (val != x) {
                queue.add(val); // keep only non-matching elements
            }
        }

        return queue;
    }

    public static void main(String[] args) {
        Queue<Integer> q1 = new LinkedList<>(Arrays.asList(1, 2, 3, 2, 4));
        Queue<Integer> q2 = new LinkedList<>(Arrays.asList(5, 5, 5));

        System.out.println("Cleaned Queue 1: " + removeAll(q1, 2)); // [1, 3, 4]
        System.out.println("Cleaned Queue 2: " + removeAll(q2, 5)); // []
    }
}
