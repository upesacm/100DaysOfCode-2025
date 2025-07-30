import java.util.*;
public class Q2 {
    public static void main(String[] args) {
        Queue<Integer> q1 = new LinkedList<>(List.of(1, 2));
        Queue<Integer> q2 = new LinkedList<>(List.of(2, 1));
        System.out.println(areQueuesEqual(q1, q2) ? "Yes" : "No");
    }

    public static boolean areQueuesEqual(Queue<Integer> q1, Queue<Integer> q2) {
        if (q1.size() != q2.size()) return false;
        Queue<Integer> temp1 = new LinkedList<>(q1);
        Queue<Integer> temp2 = new LinkedList<>(q2);
        while (!temp1.isEmpty()) {
            if (!temp1.poll().equals(temp2.poll())) return false;
        }
        return true;
    }
}
