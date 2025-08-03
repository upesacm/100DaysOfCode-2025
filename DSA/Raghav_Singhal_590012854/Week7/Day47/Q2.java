import java.util.*;

public class Q2 {

    public static Queue<Integer> insertAtFront(Queue<Integer> queue, int element) {
        Queue<Integer> temp = new LinkedList<>();
        temp.offer(element); 

        while (!queue.isEmpty()) {
            temp.offer(queue.poll()); 
        }

        return temp;
    }

    // Demo
    public static void main(String[] args) {
        Queue<Integer> q1 = new LinkedList<>(List.of(2, 3, 4));
        q1 = insertAtFront(q1, 1);
        System.out.println(q1); 
        Queue<Integer> q2 = new LinkedList<>(List.of(7, 8));
        q2 = insertAtFront(q2, 6);
        System.out.println(q2); 
    }
}
