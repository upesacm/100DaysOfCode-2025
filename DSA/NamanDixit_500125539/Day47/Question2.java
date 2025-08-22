import java.util.*;

public class Question2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> queue = new LinkedList<>();

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        System.out.println("Enter the elements:");
        for (int i = 0; i < n; i++) {
            queue.offer(sc.nextInt());
        }

        System.out.print("Enter element to insert at the front: ");
        int element = sc.nextInt();

        Queue<Integer> temp = new LinkedList<>();
        temp.offer(element); // Add to front

        while (!queue.isEmpty()) {
            temp.offer(queue.poll());
        }

        queue = temp; // Updated queue

        System.out.println(queue);
    }
}
