import java.util.*;

public class CheckUniqueQueue {
    public static boolean areAllUnique(Queue<Integer> queue) {
        Set<Integer> seen = new HashSet<>();
        boolean unique = true;
        int size = queue.size();

        for (int i = 0; i < size; i++) {
            int val = queue.remove();
            if (seen.contains(val)) {
                unique = false;
            }
            seen.add(val);
            queue.add(val); // restore queue
        }

        return unique;
    }

    public static void main(String[] args) {
        Queue<Integer> q1 = new LinkedList<>(Arrays.asList(1, 2, 3, 4));
        Queue<Integer> q2 = new LinkedList<>(Arrays.asList(1, 2, 2, 3));

        System.out.println("Queue 1 unique? " + areAllUnique(q1)); // true
        System.out.println("Queue 2 unique? " + areAllUnique(q2)); // false
    }
}
