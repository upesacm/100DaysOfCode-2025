import java.util.*;

public class Question1 {

    // Function to reverse first k elements of the queue
    public static Queue<Integer> reverseFirstK(Queue<Integer> queue, int k) {
        if (queue == null || k > queue.size() || k < 0)
            return queue;

        Stack<Integer> stack = new Stack<>();

        // Step 1: Push first k elements into a stack
        for (int i = 0; i < k; i++) {
            stack.push(queue.remove());
        }

        // Step 2: Enqueue back the stack elements
        while (!stack.isEmpty()) {
            queue.add(stack.pop());
        }

        // Step 3: Move the remaining (size-k) elements to the back to maintain order
        int remaining = queue.size() - k;
        for (int i = 0; i < remaining; i++) {
            queue.add(queue.remove());
        }

        return queue;
    }

    // Main method
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> queue = new LinkedList<>();

        System.out.print("Enter length of queue: ");
        int n = sc.nextInt();

        System.out.println("Enter the elements of the queue:");
        for (int i = 0; i < n; i++) {
            queue.add(sc.nextInt());
        }

        System.out.print("Enter the value of k: ");
        int k = sc.nextInt();

        if (k > n || k < 0) {
            System.out.println("Invalid value of k.");
        } else {
            queue = reverseFirstK(queue, k);
            for (int val : queue) {
                System.out.print(val + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}
