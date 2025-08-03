import java.util.*;

public class Q2 {
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>(List.of(2, 3, 4));
        int element = 1;
        Queue<Integer> updated = insertFront(queue, element);
        System.out.println(updated);
    }

    public static Queue<Integer> insertFront(Queue<Integer> queue, int element) {
        LinkedList<Integer> temp = new LinkedList<>();
        temp.offer(element);
        temp.addAll(queue);
        return temp;
    }
}
