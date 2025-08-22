import java.util.*;

public class Q2 {

    public static boolean compareQueues(Queue<Integer> q1, Queue<Integer> q2) {
        if (q1.size() != q2.size()) return false;

        int size = q1.size();
        boolean isEqual = true;

        for (int i = 0; i < size; i++) {
            int val1 = q1.poll();
            int val2 = q2.poll();

            if (val1 != val2) isEqual = false;

            q1.offer(val1);
            q2.offer(val2);
        }

        return isEqual;
    }

    public static void main(String[] args) {
        Queue<Integer> queue1 = new LinkedList<>(List.of(10, 20, 30));
        Queue<Integer> queue2 = new LinkedList<>(List.of(10, 20, 30));
        Queue<Integer> queue3 = new LinkedList<>(List.of(10, 30, 20));

        System.out.println(compareQueues(queue1, queue2)); 
        System.out.println(compareQueues(queue1, queue3)); 
    }
}
