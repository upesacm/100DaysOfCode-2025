import java.util.*;
public class Q1 {
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>(List.of(1, 2, 3));
        System.out.println(getQueueSum(queue));
    }

    public static int getQueueSum(Queue<Integer> queue) {
        int sum = 0;
        Queue<Integer> temp = new LinkedList<>(queue);
        while (!temp.isEmpty()) {
            sum += temp.poll();
        }
        return sum;
    }
}
