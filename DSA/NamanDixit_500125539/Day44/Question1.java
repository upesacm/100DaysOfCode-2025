import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Question1 {

    public static void traverseQueue(Queue<Integer> queue) {
        Queue<Integer> tempQueue = new LinkedList<>();

        while (!queue.isEmpty()) {
            int element = queue.poll();
            System.out.print(element + " ");
            tempQueue.offer(element);
        }

        while (!tempQueue.isEmpty()) {
            queue.offer(tempQueue.poll());
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> queue = new LinkedList<>();

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            queue.offer(sc.nextInt());
        }

        traverseQueue(queue);
    }
}
