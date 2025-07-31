import java.util.*;

public class Q1 {
    public static void main(String[] args) {
        Queue<Integer> queue1 = new LinkedList<>(List.of(10, 20, 30));
        Queue<Integer> queue2 = new LinkedList<>(List.of(5, 15));
        displayQueue(queue1);
        displayQueue(queue2);
    }

    public static void displayQueue(Queue<Integer> queue) {
        Queue<Integer> temp = new LinkedList<>(queue);
        while (!temp.isEmpty()) {
            System.out.print(temp.poll() + " ");
        }
        System.out.println();
    }
}
