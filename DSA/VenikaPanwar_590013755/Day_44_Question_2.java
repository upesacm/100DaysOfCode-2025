import java.util.*;

public class Day_44_Question_2 {
    public static int getQueueSize(Queue<Integer> queue) {
        return queue.size(); // direct property access
    }

    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>(Arrays.asList(1, 2, 3, 4));
        System.out.println("Queue size: " + getQueueSize(queue));
    }
}
