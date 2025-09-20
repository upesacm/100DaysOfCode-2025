import java.util.*;

public class QueueMin {
    public static int findMin(Queue<Integer> queue) {
        if (queue.isEmpty()) {
            throw new NoSuchElementException("Queue is empty");
        }
        int min = queue.peek();
        for (int val : queue) {
            if (val < min) min = val;
        }
        return min;
    }

    public static void main(String[] args) {
        Queue<Integer> q1 = new LinkedList<>(Arrays.asList(4, 2, 7, 1));
        System.out.println(findMin(q1)); // Output: 1

        Queue<Integer> q2 = new LinkedList<>(Arrays.asList(9, 3));
        System.out.println(findMin(q2)); // Output: 3
    }
}
