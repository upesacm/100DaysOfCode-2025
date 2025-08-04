import java.util.*;
public class Q3 {
    public static Queue<Integer> mergeQueues(Queue<Integer> q1, Queue<Integer> q2) {
        Queue<Integer> merged = new LinkedList<>(q1);
        merged.addAll(q2);
        return merged;
    }
    public static void main(String[] args) {
        Queue<Integer> q1 = new LinkedList<>(List.of(1, 2));
        Queue<Integer> q2 = new LinkedList<>(List.of(3, 4));
        Queue<Integer> merged = mergeQueues(q1, q2);
        System.out.println(merged);
    }
}
