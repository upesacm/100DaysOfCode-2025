import java.util.*;

public class Question1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> queue = new LinkedList<>();

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            queue.offer(sc.nextInt());
        }

        // Track min without modifying original queue
        int min = Integer.MAX_VALUE;
        Queue<Integer> temp = new LinkedList<>();

        while (!queue.isEmpty()) {
            int current = queue.poll();
            min = Math.min(min, current);
            temp.offer(current);
        }

        // Restore original queue
        while (!temp.isEmpty()) {
            queue.offer(temp.poll());
        }

        System.out.println(min);
    }
}
