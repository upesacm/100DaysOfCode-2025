import java.util.*;
public class Q1 {
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>(List.of(1, 2));
        int element = 3;
        insertRear(queue, element);
        System.out.println(queue);
    }

    public static void insertRear(Queue<Integer> queue, int element) {
        queue.offer(element);
    }
}
