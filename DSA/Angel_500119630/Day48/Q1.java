import java.util.*;
public class Q1 {
    public static Queue<Integer> removeOccurrences(Queue<Integer> queue, int x) {
        Queue<Integer> result = new LinkedList<>();
        while (!queue.isEmpty()) {
            int current = queue.poll();
            if (current != x) {
                result.add(current);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>(Arrays.asList(1, 2, 3, 2, 4));
        System.out.println(removeOccurrences(queue, 2));
    }
}
