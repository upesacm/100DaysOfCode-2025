import java.util.*;

public class Day_44_Question_1 {
    public static void displayQueue(Queue<Integer> queue) {
        int size = queue.size();
        for (int i = 0; i < size; i++) {
            int front = queue.remove();
            System.out.print(front + " ");
            queue.add(front); // reinsert to preserve order
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>(Arrays.asList(10, 20, 30));
        System.out.print("Queue contents: ");
        displayQueue(queue);
        System.out.println("After display, queue remains: " + queue);
    }
}
