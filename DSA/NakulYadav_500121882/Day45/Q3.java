import java.util.*;
public class Q3 {
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>(List.of(10, 7, 4));
        System.out.println(getMaxInQueue(queue));
    }

    public static int getMaxInQueue(Queue<Integer> queue) {
        int max = Integer.MIN_VALUE;
        Queue<Integer> temp = new LinkedList<>(queue);
        while (!temp.isEmpty()) {
            int val = temp.poll();
            if (val > max) max = val;
        }
        return max;
    }
}
