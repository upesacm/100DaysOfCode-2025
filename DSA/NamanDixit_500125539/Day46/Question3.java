import java.util.*;

public class Question3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Queue<Integer> queue1 = new LinkedList<>();
        Queue<Integer> queue2 = new LinkedList<>();
        Queue<Integer> mergedQueue = new LinkedList<>();

        System.out.print("Enter number of elements in Queue 1: ");
        int n1 = sc.nextInt();
        System.out.println("Enter elements of Queue 1:");
        for (int i = 0; i < n1; i++) {
            queue1.offer(sc.nextInt());
        }

        System.out.print("Enter number of elements in Queue 2: ");
        int n2 = sc.nextInt();
        System.out.println("Enter elements of Queue 2:");
        for (int i = 0; i < n2; i++) {
            queue2.offer(sc.nextInt());
        }

        // Sequentially append all elements from queue1 and queue2 into mergedQueue
        Queue<Integer> temp1 = new LinkedList<>();
        Queue<Integer> temp2 = new LinkedList<>();

        while (!queue1.isEmpty()) {
            int val = queue1.poll();
            mergedQueue.offer(val);
            temp1.offer(val); // preserve queue1
        }

        while (!queue2.isEmpty()) {
            int val = queue2.poll();
            mergedQueue.offer(val);
            temp2.offer(val); // preserve queue2
        }

        // Restore original queues
        while (!temp1.isEmpty()) {
            queue1.offer(temp1.poll());
        }
        while (!temp2.isEmpty()) {
            queue2.offer(temp2.poll());
        }

        System.out.println("Merged Queue:");
        for (int val : mergedQueue) {
            System.out.print(val + " ");
        }
        System.out.println();
    }
}
