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

        int evenCount = 0;
        int oddCount = 0;
        Queue<Integer> temp = new LinkedList<>();

        while (!queue.isEmpty()) {
            int val = queue.poll();
            if (val % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
            temp.offer(val);
        }

        while (!temp.isEmpty()) {
            queue.offer(temp.poll());
        }

        System.out.println("Even: " + evenCount);
        System.out.println("Odd: " + oddCount);
    }
}
