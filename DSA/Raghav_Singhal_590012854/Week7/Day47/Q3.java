import java.util.*;

public class Q3 {

    public static void getFrontAndRear(Queue<Integer> queue) {
        if (queue.isEmpty()) {
            System.out.println("Queue is empty");
            return;
        }

        int size = queue.size();
        int front = queue.peek();
        int rear = -1;

        for (int i = 0; i < size; i++) {
            int val = queue.poll();
            if (i == size - 1) {
                rear = val;
            }
            queue.offer(val); 
        }

        System.out.println("Front: " + front + ", Rear: " + rear);
    }

    public static void main(String[] args) {
        Queue<Integer> q1 = new LinkedList<>(List.of(10, 20, 30));
        getFrontAndRear(q1);
        Queue<Integer> q2 = new LinkedList<>();
        getFrontAndRear(q2); 
    }
}
