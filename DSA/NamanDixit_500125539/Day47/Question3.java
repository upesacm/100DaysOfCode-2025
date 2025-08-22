
import java.util.*;

public class Question3 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> queue = new LinkedList<>();

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            queue.offer(sc.nextInt());
        }
        // Retrieve front and rear
        if (queue.isEmpty()) {
            System.out.println("Queue is empty.");
        } else {
            System.out.println("Front: " + queue.peek());

            // To get rear element, iterate through queue
            int rear = -1;
            for (int val : queue) {
                rear = val;
            }
            System.out.println("Rear: " + rear);
        }
    }
}
