import java.util.*;

public class Q1 {

    public static Queue<Integer> reverseFirstK(Queue<Integer> queue, int k) {
        if (queue == null || k > queue.size() || k < 0) return queue;

        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < k; i++) {
            stack.push(queue.poll());
        }
        while (!stack.isEmpty()) {
            queue.offer(stack.pop());
        }

        int remaining = queue.size() - k;
        for (int i = 0; i < remaining; i++) {
            queue.offer(queue.poll());
        }

        return queue;
    }

    public static void main(String[] args) {
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= 5 ;i++) q.offer(i);

        Queue<Integer> result = reverseFirstK(q, 3);
        System.out.println(result);
    }
}