import java.util.*;

public class InsertAtFront {
    public static Queue<Integer> insertFront(Queue<Integer> queue, int element) {
        LinkedList<Integer> list = new LinkedList<>(queue); // Allow front insertion
        list.addFirst(element);
        return list;
    }

    public static void main(String[] args) {
        Queue<Integer> q = new LinkedList<>(Arrays.asList(2, 3, 4));
        int toInsert = 1;

        Queue<Integer> result = insertFront(q, toInsert);
        System.out.println("Updated Queue: " + result);
    }
}
