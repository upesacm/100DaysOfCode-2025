import java.util.*;

public class Q2 {
    public static void main(String[] args) {
        Queue<Integer> queue1 = new LinkedList<>(List.of(1, 2, 3, 4));
        Queue<Integer> queue2 = new LinkedList<>(List.of(7));
        System.out.println(getQueueSize(queue1));
        System.out.println(getQueueSize(queue2));
    }

    public static int getQueueSize(Queue<Integer> queue) {
        return queue.size();
    }
}
