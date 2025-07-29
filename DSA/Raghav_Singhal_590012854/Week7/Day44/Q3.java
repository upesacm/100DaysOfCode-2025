import java.util.*;

public class Q3 {

    public static boolean isQueueEmpty(Queue<?> queue) {
        return queue.isEmpty();  
    }

    public static void main(String[] args) {
        Queue<Integer> q1 = new LinkedList<>();
        Queue<String> q2 = new LinkedList<>(List.of("data"));

        System.out.println(isQueueEmpty(q1)); 
        System.out.println(isQueueEmpty(q2)); 
    }
}
