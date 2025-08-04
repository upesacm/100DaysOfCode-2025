import java.util.*;
public class Q1 {
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>(List.of(1, 2, 3, 4, 5));
        int k = 3;
        reverseFirstK(queue, k);
        System.out.println(queue);
    }

    public static void reverseFirstK(Queue<Integer> queue, int k) {
        if (queue == null || k > queue.size() || k < 0) return;
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < k; i++) {
            stack.push(queue.poll());
        }
        while (!stack.isEmpty()) {
            queue.add(stack.pop());
        }
        int size = queue.size();
        for (int i = 0; i < size - k; i++) {
            queue.add(queue.poll());
        }
    }
}
