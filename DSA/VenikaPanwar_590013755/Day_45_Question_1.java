import java.util.*;

public class Day_45_Question_1 {
    public static int sumQueue(Queue<Integer> queue) {
        int size = queue.size();
        int sum = 0;

        for (int i = 0; i < size; i++) {
            int val = queue.remove();
            sum += val;
            queue.add(val); // reinsert to maintain original structure
        }

        return sum;
    }

    public static void main(String[] args) {
        Queue<Integer> q = new LinkedList<>(Arrays.asList(1, 2, 3));
        int result = sumQueue(q);
        System.out.println("Sum of elements: " + result);
        System.out.println("Queue remains: " + q);
    }
}
