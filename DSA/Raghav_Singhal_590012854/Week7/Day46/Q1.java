import java.util.*;

public class Q1 {

    public static int findMinInQueue(Queue<Integer> queue) {
        int size = queue.size();
        int min = Integer.MAX_VALUE;

        for (int i = 0; i < size; i++) {
            int val = queue.poll();
            if (val < min) {
                min = val;
            }
            queue.offer(val); 
        }

        return min;
    }

    public static void main(String[] args) {
        Queue<Integer> queue1 = new LinkedList<>(List.of(10, 20, 30));
        System.out.println("Min in queue1: " + findMinInQueue(queue1)); 
        Queue<Integer> queue2 = new LinkedList<>(List.of(5, 15, 2, 100));
        System.out.println("Min in queue2: " + findMinInQueue(queue2)); 
    }
}
