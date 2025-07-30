import java.util.*;

public class Day_45_Question_2 {
    public static boolean areQueuesEqual(Queue<Integer> q1, Queue<Integer> q2) {
        if (q1.size() != q2.size()) return false;

        int size = q1.size();
        boolean same = true;

        for (int i = 0; i < size; i++) {
            int val1 = q1.remove();
            int val2 = q2.remove();

            if (val1 != val2) same = false;

            q1.add(val1); // maintain original structure
            q2.add(val2);
        }

        return same;
    }

    public static void main(String[] args) {
        Queue<Integer> q1 = new LinkedList<>(Arrays.asList(1, 2, 3));
        Queue<Integer> q2 = new LinkedList<>(Arrays.asList(1, 2, 3));
        Queue<Integer> q3 = new LinkedList<>(Arrays.asList(2, 1));

        System.out.println("q1 vs q2: " + (areQueuesEqual(q1, q2) ? "Yes" : "No")); // Yes
        System.out.println("q1 vs q3: " + (areQueuesEqual(q1, q3) ? "Yes" : "No")); // No
    }
}
