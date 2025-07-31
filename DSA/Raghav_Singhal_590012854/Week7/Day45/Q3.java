import java.util.*;

public class Q3 {

    public static int findMax(Queue<Integer> queue) {
        int size = queue.size();
        int max = Integer.MIN_VALUE;

        for (int i = 0; i < size; i++) {
            int val = queue.poll();
            max = Math.max(max, val);
            queue.offer(val); 
        }

        return max;
    }

    // Demo
    public static void main(String[] args) {
        Queue<Integer> queue1 = new LinkedList<>(List.of(4, 7, 1, 9, 2));
        Queue<Integer> queue2 = new LinkedList<>(List.of(15, 5, 12));

        System.out.println(findMax(queue1));
        System.out.println(findMax(queue2)); 
    }
}
