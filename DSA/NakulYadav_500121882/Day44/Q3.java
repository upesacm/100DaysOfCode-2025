import java.util.*;

public class Q3 {
    public static void main(String[] args) {
        Queue<Integer> queue1 = new LinkedList<>();
        Queue<Integer> queue2 = new LinkedList<>(List.of(1, 2));
        System.out.println(isQueueEmpty(queue1));
        System.out.println(isQueueEmpty(queue2));
    }

    public static boolean isQueueEmpty(Queue<Integer> queue) {
        return queue.isEmpty();
    }
}
