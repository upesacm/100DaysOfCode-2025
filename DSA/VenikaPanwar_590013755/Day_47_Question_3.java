import java.util.*;

public class FrontAndRear {
    public static void printFrontAndRear(Queue<Integer> queue) {
        if (queue.isEmpty()) {
            System.out.println("Queue is empty");
            return;
        }

        int front = queue.peek();
        int rear = -1;

        for (int val : queue) rear = val;

        System.out.println("Front: " + front + ", Rear: " + rear);
    }

    public static void main(String[] args) {
        Queue<Integer> q1 = new LinkedList<>(Arrays.asList(10, 20, 30));
        Queue<Integer> q2 = new LinkedList<>();

        System.out.print("Queue 1 -> ");
        printFrontAndRear(q1); // Output: Front: 10, Rear: 30

        System.out.print("Queue 2 -> ");
        printFrontAndRear(q2); // Output: Queue is empty
    }
}
