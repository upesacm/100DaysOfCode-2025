import java.util.*;

public class Day_44_Question_3 {
    public static boolean isEmpty(Queue<Integer> queue) {
        return queue.isEmpty();
    }

    public static void main(String[] args) {
        Queue<Integer> queue1 = new LinkedList<>();
        Queue<Integer> queue2 = new LinkedList<>(Arrays.asList(1, 2));

        System.out.println("Queue1 empty? " + isEmpty(queue1)); // true
        System.out.println("Queue2 empty? " + isEmpty(queue2)); // false
    }
}
