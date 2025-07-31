import java.util.*;

public class Q3 {

    public static void mergeQueues(Queue<Integer> q1, Queue<Integer> q2) {
        int sizeQ2 = q2.size();

        for (int i = 0; i < sizeQ2; i++) {
            int val = q2.poll();
            q1.offer(val);     
            q2.offer(val);     
        }

        System.out.println("Merged Queue: " + q1);
    }

    // Demo
    public static void main(String[] args) {
        Queue<Integer> queue1 = new LinkedList<>(List.of(1, 2));
        Queue<Integer> queue2 = new LinkedList<>(List.of(3, 4));
        mergeQueues(queue1, queue2); 

        Queue<Integer> q1 = new LinkedList<>(List.of(5));
        Queue<Integer> q2 = new LinkedList<>(List.of(6, 7));
        mergeQueues(q1, q2); 
    }
}
