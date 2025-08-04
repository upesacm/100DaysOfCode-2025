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

        System.out.print("Enter element to remove: ");
        int target = sc.nextInt();

        Queue<Integer> tempQueue = new LinkedList<>();
        while (!queue.isEmpty()) {
            int current = queue.poll();
            if (current != target) {
                tempQueue.offer(current);
            }
        }

        queue = tempQueue;

        System.out.println(queue);
    }
}
