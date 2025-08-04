import java.util.*;

public class Q3 {
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>(List.of(10, 20, 30));
        printFrontRear(queue);
    }

    public static void printFrontRear(Queue<Integer> queue) {
        if (queue.isEmpty()) {
            System.out.println("Queue is empty");
            return;
        }

        int front = queue.peek();
        int rear = 0;
        for (int val : queue) rear = val;

        System.out.println("Front: " + front + ", Rear: " + rear);
    }
}
