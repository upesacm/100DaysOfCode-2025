import java.util.*;

public class Day_43_Question_1 {
    public static Queue<Integer> reverseFirstK(Queue<Integer> queue, int k) {
        if (queue == null || k > queue.size() || k <= 0) return queue;

        Stack<Integer> stack = new Stack<>();

        // Step 1: Push first k elements into stack
        for (int i = 0; i < k; i++) {
            stack.push(queue.remove());
        }

        // Step 2: Enqueue back reversed elements
        while (!stack.isEmpty()) {
            queue.add(stack.pop());
        }

        // Step 3: Move the remaining elements to the back
        int size = queue.size();
        for (int i = 0; i < size - k; i++) {
            queue.add(queue.remove());
        }

        return queue;
    }

    public static void main(String[] args) {
        Queue<Integer> q = new LinkedList<>(Arrays.asList(1, 2, 3, 4, 5));
        int k = 3;

        Queue<Integer> result = reverseFirstK(q, k);
        System.out.println("Modified Queue: " + result);
    }
}
