import java.util.*;

public class MergeQueues {
    public static Queue<Integer> merge(Queue<Integer> q1, Queue<Integer> q2) {
        Queue<Integer> merged = new LinkedList<>(q1); // Copy of q1
        merged.addAll(q2);
        return merged;
    }

    public static void main(String[] args) {
        Queue<Integer> q1 = new LinkedList<>(Arrays.asList(1, 2));
        Queue<Integer> q2 = new LinkedList<>(Arrays.asList(3, 4));
        System.out.println(merge(q1, q2)); // Output: [1, 2, 3, 4]

        Queue<Integer> q3 = new LinkedList<>(Arrays.asList(5));
        Queue<Integer> q4 = new LinkedList<>(Arrays.asList(6, 7));
        System.out.println(merge(q3, q4)); // Output: [5, 6, 7]
    }
}
