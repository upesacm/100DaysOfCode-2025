import java.util.*;

public class Day_45_Question_3 {
    public static int findMax(Queue<Integer> queue) {
        if (queue.isEmpty()) return -1;

        int size = queue.size();
        int max = Integer.MIN_VALUE;

        for (int i = 0; i < size; i++) {
            int val = queue.remove();
            max = Math.max(max, val);
            queue.add(val); // restore
        }

        return max;
    }

    public static void main(String[] args) {
        Queue<Integer> q1 = new LinkedList<>(Arrays.asList(3, 5, 1, 2));
        Queue<Integer> q2 = new LinkedList<>(Arrays.asList(10, 7, 4));

        System.out.println("Max in q1: " + findMax(q1)); // 5
        System.out.println("Max in q2: " + findMax(q2)); // 10
    }
}
